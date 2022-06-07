#include "ControleChefaoPulador.h"
#include "Tempo.h"
#include "Jogador.h"
#include "ChefaoPulador.h"
#include "GerenciadorColisoes.h"
#include "Plataforma.h"
using namespace Configs;
namespace Componentes
{
    ControleChefaoPulador::ControleChefaoPulador()
    :ControleInimigo(Vector2f(0.3,-0.26),3,14,0.3),cima(nullptr),baixo(nullptr),tempoPularCount(0),tempoPular(1+4*((float)rand())/RAND_MAX)
    {
        coelhoDireita.loadFromFile("Arquivos/Imagens/chefeDir.png");
        coelhoEsquerda.loadFromFile("Arquivos/Imagens/chefeEsq.png");
    }
    ControleChefaoPulador::~ControleChefaoPulador()
    {
        Soltar();
    }
    void ControleChefaoPulador::Soltar()
    {
        if(cima)
            cima->setBaixo(nullptr);
        if(baixo)
            baixo->setCima(nullptr);
        cima=nullptr;
        baixo=nullptr;
    }
    void ControleChefaoPulador::Render()
    {
        if(indoDireita)
            gS->getSprite()->setTextura(coelhoDireita);
        else
            gS->getSprite()->setTextura(coelhoEsquerda);
    }
    void ControleChefaoPulador::Atualizar()
    {
        ControleInimigo::Atualizar();
        if(tempoPularCount<10*tempoPular)
        {
            tempoPularCount+=Tempo::getDeltaTempoControlado();
        }
    }
    void ControleChefaoPulador::AtualizarFixo()
    {
        if(!vida->Vivo())
        {
            getEntidade()->Destruir();
            Jogador::darPontos(10);
        } else if(!baixo)//se nao tiver objeto abaixo
        {
            cR->setGravidade(true);
            TestarChao();
            Vector2f vel = cR->getVelocidade();
            if(!esquerdaChao && !direitaChao)
            {
                if(pos->getY()<-20)
                    pos->setPos(Vector2f(20,2));
            }
            else if(indoDireita && !direitaChao)
            {
                cR->setVelocidade(Vector2f(-movimento.getVelocidade(),vel.y));
                indoDireita = false;
            }
            else if(!indoDireita && !esquerdaChao)
            {
                cR->setVelocidade(Vector2f(movimento.getVelocidade(),vel.y));
                indoDireita=true;
            }
            else
            {
                cR->setVelocidade(Vector2f((indoDireita)?movimento.getVelocidade():-movimento.getVelocidade(),vel.y));
            }
        }
        else
        {
            cR->setGravidade(false);
            pos->setPos(baixo->pos->getPos()+Vector2f(0,0.5));
        }
        if(cima)
        {
            movimento.setModVelocidade(0.5);
        }
        Pular();
    }
    void ControleChefaoPulador::Pular()
    {
        if((tempoPularCount>tempoPular&& (!cima||(!cima&&!baixo)))
        ||(tempoPularCount>tempoPular*8&&cima &&!baixo)
        ||(tempoPularCount>tempoPular*5&&cima&&baixo))
        {
            Vector2f posi = cR->getCentro()+Vector2f(-5,5);
            Vector2f dime = Vector2f(10,10);
            Colisor col(&posi,&dime);
            list<ObjetoFisico*> objs = GerenciadorColisoes::EncontraColisao(col);
            vector<Vector2f> vec;
            vector<Vector2f> jog;
            for(auto obj : objs)
            {
                CorpoRigido* cp = obj->getCorpoRigido();
                if(cp)
                {
                    Entidade* ent = cp->getEntidade();
                    if(ent->temTag(Jogador::TAG_JOGADOR))
                    {
                        jog.push_back(cp->getCentro());
                    }
                    else if (ent!=getEntidade()&&ent->temTag(ChefaoPulador::TAG_CHEFAO))
                    {
                        
                        ControleChefaoPulador* cont=ent->getComponente<ControleChefaoPulador>();
                        //testa se tem espaco para pular
                        if(cont->getCima())
                            continue;
                        //testa se esta na pilha de coelhos
                        while(cont!=nullptr)
                        {
                            if(cont->getEntidade()==getEntidade())
                                continue;
                            cont = cont->getBaixo();
                        }
                        vec.push_back(cp->getCentro());
                    }
                    
                }
            }
            int probabilidade = rand()%100;
            //20% de atacar o player
            if(probabilidade<20 && !jog.empty())
            {
                Vector2f direc = jog[rand()%jog.size()]-cR->getCentro();
                float normainv = sqrt(direc.x*direc.x+direc.y*direc.y);
                normainv= (normainv==0)?0:1/normainv;
                
                cR->setVelocidade(movimento.getPulo()*normainv*direc);
            } //35% de pular em outro coelho
            else if(probabilidade>=20&&probabilidade<70 && !vec.empty())
            {
                Vector2f direc = vec[rand()%vec.size()]-cR->getCentro();
                float normainv = 1/sqrt(direc.x*direc.x+direc.y*direc.y);
                cR->setVelocidade(movimento.getPulo()*normainv*direc);
            }
            else //45% de pular aleatoriamente
            {
                int modX= (rand()%2)?1:-1,
                modY= (esquerdaChao||direitaChao)? 1 :(rand()%2)?1:-1;
                cR->setVelocidade(movimento.getPulo()*Vector2f(0.7*modX,0.7*modY));
            }
            tempoPular = 1+4*((float)rand())/RAND_MAX;
            tempoPularCount=0;
            //seta direcao
            Soltar();
            if(cR->getVelocidade().x>0)
            {
                indoDireita=true;
            }else if(cR->getVelocidade().x<0)
            {
                indoDireita=false;
            }
        }

    }
    ControleChefaoPulador* ControleChefaoPulador::getCima()
    {
        return cima;
    }
    ControleChefaoPulador* ControleChefaoPulador::getBaixo()
    {
        return baixo;
    }
    void ControleChefaoPulador::setCima(ControleChefaoPulador* cm)
    {
        cima=cm;
    }
    void ControleChefaoPulador::setBaixo(ControleChefaoPulador* bx)
    {
        baixo=bx;
    }
    void ControleChefaoPulador::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            
            CorpoRigido* coR = obj->getCorpoRigido();

            if(coR&&coR->getEntidade()->temTag(ChefaoPulador::TAG_CHEFAO))
            {
                if(!baixo&&!cima&&tempoPularCount>0.1)
                {
                    ControleChefaoPulador* cpp = coR->getEntidade()->getComponente<ControleChefaoPulador>();
                    while(cpp->getCima()!=nullptr)
                    {
                        cpp=cpp->getCima();
                    }
                    cpp->cima=this;
                    this->baixo=cpp;
                }
                return;
            }else if(objEmCima(obj))
            {
                obj->setVel(Vector2f(obj->getVel().x,2));
                if(coR->getEntidade()->temTag(Jogador::TAG_JOGADOR))
                    vida->Machucar(1);
            }else 
            {
                
                if (!objEmBaixo(obj))
                {
                    Vector2f dir = obj->getColisor().getCentro()-cR->getCentro();
                    //obj->addVel(Vector2f(dir.x*(-8.0F),0));
                    if((dir.x>0&&indoDireita)||(dir.x<0&&!indoDireita))
                        indoDireita=!indoDireita;
                }
                if(cR)
                {
                    Entidade* ent =coR->getEntidade();
                    if(ent && ent->temTag(Jogador::TAG_JOGADOR))
                    {
                        ent->getComponente<Vida>()->Machucar(1);
                    }

                }
                    
            }
        }
        
    }
    const float ControleChefaoPulador::getTempoRec() const
    {
        return tempoPular;
    }
    const float ControleChefaoPulador::getTempoCont() const
    {
        return tempoPularCount;
    }
    void ControleChefaoPulador::setTempoRec(float tempo)
    {
        tempoPular=tempo;
    }
    void ControleChefaoPulador::setTempoCont(float tempo)
    {
        tempoPularCount=tempo;
    }
    
}