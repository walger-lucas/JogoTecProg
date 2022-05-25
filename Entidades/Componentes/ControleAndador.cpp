#include "ControleAndador.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
using namespace sf;
using namespace Entidades;
namespace Componentes
{
    const Vector2f posBuscChao(0.6,-0.51);
    ControleAndador::ControleAndador()
    :Componente(),pos(nullptr),cR(nullptr),vida(nullptr),velocidade(2)
    {}
    ControleAndador::~ControleAndador()
    {}
    void ControleAndador::Iniciar()
    {
        pos = getEntidade()->getComponente<Posicao>();
        cR = getEntidade()->getComponente<CorpoRigido>();
        vida = getEntidade()->getComponente<Vida>();
        cR->addEscuta(this);
        indoDireita=true;
    }
    void ControleAndador::TestarChao()
    {
        list<ObjetoFisico*> l = Gerenciadores::GerenciadorColisoes::EncontraColisao(cR->getCentro()+posBuscChao);
        direitaChao=false;
        for(ObjetoFisico* ob : l)
        {
            CorpoRigido* cp =ob->getCorpoRigido();
            if(cp!=nullptr&& cp->getEntidade()->temTag(Entidades::TAG_GROUND))
            {
                direitaChao=true;
                
            }
        }
        Vector2f pos = posBuscChao;
        pos.x*=-1;
        l=Gerenciadores::GerenciadorColisoes::EncontraColisao(cR->getCentro()+pos);
        esquerdaChao=false;
        for(ObjetoFisico* ob : l)
        {
            CorpoRigido* cp =ob->getCorpoRigido();
            if(cp!=nullptr&& cp->getEntidade()->temTag(Entidades::TAG_GROUND))
            {
                esquerdaChao=true;
            }
        }
        
    }
    void ControleAndador::AtualizarFixo()
    {
        if(!vida->Vivo())
            getEntidade()->Destruir();
        TestarChao();
        Vector2f vel = cR->getVelocidade();
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
    void ControleAndador::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            
            Colisor& col = obj->getColisor();
            if(col.getPos().y-col.getDim().y>=pos->getY()-0.05)
            {
                obj->setVel(Vector2f(obj->getVel().x,4.5));
                vida->Machucar(1);
            }else 
            {
                if (pos->getY()-cR->getDim().y<=col.getPos().y-col.getDim().y)
                {
                    Vector2f dir = col.getCentro()-cR->getCentro();
                    obj->addVel(dir*(-8.0F));
                    if((dir.x>0&&indoDireita)||(dir.x<0&&!indoDireita))
                        indoDireita=!indoDireita;
                }
                CorpoRigido* cR = obj->getCorpoRigido();
                if(cR)
                {
                    Entidade* ent =cR->getEntidade();
                    if(ent && ent->temTag(TAG_JOGADOR))
                    {
                        ent->getComponente<Vida>()->Machucar(1);
                    }

                }
                    
            }
        }
        
    }
}