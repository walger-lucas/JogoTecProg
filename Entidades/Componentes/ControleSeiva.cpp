#include "ControleSeiva.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"

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
        { // Verificar como fazer para reduzir a velocidade
            obj->setVel(Vector2f(obj->getVel().x * 0.1, obj->getVel().y));
        }
    }
}