#include "ControleAndador.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleAndador::ControleAndador()
    :ControleInimigo(Vector2f(0.6,-0.51)),velocidade(2)
    {}
    ControleAndador::~ControleAndador()
    {}

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
            
            
            if(objEmCima(obj))
            {
                obj->setVel(Vector2f(obj->getVel().x,4.5));
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