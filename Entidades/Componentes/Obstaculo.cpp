#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    void Obstaculo::Iniciar()
    {
        pos = getEntidade()->getComponente<Posicao>();
        gS = getEntidade()->getComponente<GraficoSprite>();
        cR = getEntidade()->getComponente<CorpoRigido>();
        vida = getEntidade()->getComponente<Vida>();
        cR->addEscuta(this);
    }

    bool Obstaculo::objEmCima(ObjetoFisico* obj)
    {
        Colisor& col = obj->getColisor();
        return col.getPos().y-col.getDim().y>=pos->getY()-0.1;
    }

    Obstaculo::Obstaculo()
    { }
    Obstaculo::~Obstaculo()
    { }
}