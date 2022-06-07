#include "ControleObstaculo.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"

using namespace sf;
using namespace Entidades;
namespace Componentes
{
    const string ControleObstaculo::TAG_OBSTACULO="obstaculo";
    void ControleObstaculo::Iniciar()
    {
        pos = getEntidade()->getComponente<Posicao>();
        cR = getEntidade()->getComponente<CorpoRigido>();
        cR->addEscuta(this);
    }

    bool ControleObstaculo::objEmCima(ObjetoFisico* obj)
    {
        Colisor& col = obj->getColisor();
        return col.getPos().y-col.getDim().y>=pos->getY()-0.1;
    }

    ControleObstaculo::ControleObstaculo()
    { }
    ControleObstaculo::~ControleObstaculo()
    { }
}