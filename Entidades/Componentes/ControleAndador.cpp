#include "ControleAndador.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
#include "Projetil.h"
using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleAndador::ControleAndador()
    :ControleInimigo(Vector2f(0.6,-0.51),2,4,0.4)
    {}
    ControleAndador::~ControleAndador()
    {}

    void ControleAndador::AtualizarFixo()
    {
        if(!vida->Vivo())
        {
            getEntidade()->Destruir();
            Jogador::darPontos(5);
        }
            
        TestarChao();
        Vector2f vel = cR->getVelocidade();
        if(!esquerdaChao && !direitaChao)
            cR->setVelocidade(Vector2f(0,vel.y));
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
    void ControleAndador::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            
            CorpoRigido* coR = obj->getCorpoRigido();
            if(objEmCima(obj))
            {
                obj->setVel(Vector2f(obj->getVel().x,4.5));
                if(coR->getEntidade()->temTag(Jogador::TAG_JOGADOR))
                    vida->Machucar(1);
            }else 
            {
                
                if (!objEmBaixo(obj))
                {
                    Vector2f dir = obj->getColisor().getCentro()-cR->getCentro();
                    obj->addVel(Vector2f(dir.x*(-8.0F),0));
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
}