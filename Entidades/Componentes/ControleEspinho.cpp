#include "ControleEspinho.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleEspinho::ControleEspinho():
    ControleObstaculo()
    {}

    ControleEspinho::~ControleEspinho()
    {}


    void ControleEspinho::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        {
            CorpoRigido* coR = obj->getCorpoRigido();
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
    void ControleEspinho::AtualizarFixo()
    {
        cR->setVelocidade(Vector2f(0,cR->getVelocidade().y));
    }
}