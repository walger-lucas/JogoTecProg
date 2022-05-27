#include "ControleExplodidor.h"
#include "Tempo.h"
#include "Jogador.h"
#include "Projetil.h"
#include "Cena.h"
#include "Andador.h"
using namespace Entidades;
namespace Componentes
{
    ControleExplodidor::ControleExplodidor(float rec)
    :ControleInimigo(Vector2f(0.8,-0.8)),recarga(4),velocidade(1.4),distAtv(4)
    {
        cont_recarga=rec;
        comEspinhos.loadFromFile("Arquivos/Imagens/Explodidor_B.png");
        semEspinhos.loadFromFile("Arquivos/Imagens/Explodidor_A.png");
    }
    void ControleExplodidor::Iniciar()
    {
        ControleInimigo::Iniciar();
        if(cont_recarga>=recarga)
            gS->getSprite()->setTextura(comEspinhos);
        else
            gS->getSprite()->setTextura(semEspinhos);

    }
    void ControleExplodidor::ExplodirEspinhos()
    {
        if(cont_recarga>=2.5*recarga&&
        ((Jogador::Jimmy&&fabs(pos->getX()- Jogador::Jimmy->getComponente<Posicao>()->getX())<distAtv)
        ||(Jogador::Janny&&fabs(pos->getX()- Jogador::Janny->getComponente<Posicao>()->getX())<distAtv)))
        {
            cont_recarga=0;
            Cena* cen = getEntidade()->getCena();
            Vector2f pos = cR->getCentro();
            *cen+= new Projetil(pos+Vector2f(-1.1,1.1),Vector2f(-2,2));
            *cen+= new Projetil(pos+Vector2f(-0.5,1.5),Vector2f(-1.5,3));
            *cen+= new Projetil(pos+Vector2f(0.5,1.5),Vector2f(1.5,3));
            *cen+= new Projetil(pos+Vector2f(1.1,1.1),Vector2f(2,2));
            *cen+= new Projetil(pos+Vector2f(-1.4,0.5),Vector2f(-2,0.1));
            *cen+= new Projetil(pos+Vector2f(1.0,0.5),Vector2f(2,0.1));
            gS->getSprite()->setTextura(semEspinhos);
            
        }
        else if(cont_recarga>=recarga)
        {
           gS->getSprite()->setTextura(comEspinhos); 
        }
    }
    ControleExplodidor::~ControleExplodidor()
    {}
    void ControleExplodidor::Atualizar()
    {
        if(cont_recarga<10*recarga)
            cont_recarga+=Configs::Tempo::getDeltaTempoControlado();
    }
    void ControleExplodidor::AtualizarFixo()
    {
        if(!vida->Vivo())
            getEntidade()->Destruir();

        TestarChao();
        ExplodirEspinhos();
        Vector2f vel = cR->getVelocidade();
        if(cont_recarga<recarga)
        {
            cR->setVelocidade(Vector2f(0,vel.y));
            indoDireita = rand()%2;
            return;
        }
            
        

        if(!esquerdaChao && !direitaChao)
            cR->setVelocidade(Vector2f(0,vel.y));
        else if(indoDireita && !direitaChao)
        {
            cR->setVelocidade(Vector2f(-velocidade,vel.y));
            indoDireita = false;
        }
        else if(!indoDireita && !esquerdaChao)
        {
            cR->setVelocidade(Vector2f(velocidade,vel.y));
            indoDireita=true;
        }
        else
        {
            cR->setVelocidade(Vector2f((indoDireita)?velocidade:-velocidade,vel.y));
        }
    }
    void ControleExplodidor::Colidiu(ObjetoFisico* obj){
        if(obj &&obj->getColidivel()&&obj->getCinematico())
        {
            CorpoRigido* coR = obj->getCorpoRigido();
            if(objEmCima(obj) )
            {
                if(coR&& !coR->getEntidade()->temTag(Projetil::TAG_PROJETIL))
                {
                    obj->setVel(Vector2f(obj->getVel().x,4.5));
                    if(cont_recarga<recarga &&coR->getEntidade()->temTag(Jogador::TAG_JOGADOR))
                    {
                        vida->Machucar(1);
                        return;
                    }
                }
                    
            }else
            if (!objEmBaixo(obj))
            {
                Vector2f dir = obj->getColisor().getCentro()-cR->getCentro();
                obj->addVel(Vector2f(dir.x*(-8.0F),0));
                if((dir.x>0&&indoDireita)||(dir.x<0&&!indoDireita))
                    indoDireita=!indoDireita;
            }
            
            if(coR&&recarga<cont_recarga)
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