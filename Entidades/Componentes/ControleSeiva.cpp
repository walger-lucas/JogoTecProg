#include "ControleSeiva.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
#include "Andador.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleSeiva::ControleSeiva():
    Obstaculo()
    {}

    ControleSeiva::~ControleSeiva()
    {}

    void ControleSeiva::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            CorpoRigido* coR = obj->getCorpoRigido();
            if(cR)
            {
                Entidade* ent =coR->getEntidade();
                if(ent && ent->temTag(Jogador::TAG_JOGADOR))
                {
                    ent->getComponente<ControleJogador>()->setModVelocidade(0.5);
                    ent->getComponente<ControleJogador>()->setModPulo(0.5);
                }
            }
            obj->setVel(Vector2f(obj->getVel().x * 0.1, obj->getVel().y));
        }
    }
}