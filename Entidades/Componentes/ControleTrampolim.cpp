#include "ControleTrampolim.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    ControleTrampolim::ControleTrampolim():
    Obstaculo()
    {}

    ControleTrampolim::~ControleTrampolim()
    {}


    void ControleTrampolim::Colidiu(ObjetoFisico* obj)
    {
        if(obj &&obj->getColidivel())
        { // Mudar a forma de verificar se está pressionando para baixo
            if(objEmCima(obj) && !(Keyboard::isKeyPressed(Keyboard::Key::Down)))
            {
                obj->setVel(Vector2f(obj->getVel().x,6.5));
            } 
        }
    }
}