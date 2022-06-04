#include "ControleSeiva.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
#include "Andador.h"
#include "Plataforma.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleSeiva::ControleSeiva():
    Obstaculo()
    {}

    ControleSeiva::~ControleSeiva()
    {}
    void ControleSeiva::AtualizarFixo()
    {
        if(!cR->getGravidade())
        {
            cR->setVelocidade(Vector2f(0,0));
        }
    }
    void ControleSeiva::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            CorpoRigido* coR = obj->getCorpoRigido();
            if(cR)
            {
                Entidade* ent =coR->getEntidade();
                if(ent)
                {
                    ControleJogador* jog =ent->getComponente<ControleJogador>();
                    if(jog)
                    {
                        jog->setModVelocidade(0.3);
                        jog->setModPulo(0.2);

                    }
                    ControleInimigo* inimigo =ent->getComponente<ControleInimigo>();
                    if(inimigo)
                    {
                        inimigo->setModVelocidade(0.3);
                        inimigo->setModPulo(0.2);
                    }
                }
                if(ent && ent->temTag(Plataforma::TAG_GROUND))
                {
                    cR->setGravidade(false);
                }
            }
            obj->setVel(Vector2f(obj->getVel().x * 0.1, obj->getVel().y));
        }
    }
}