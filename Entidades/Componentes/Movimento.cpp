#include "Movimento.h"
#include "Configs/Tempo.h"
using namespace Configs;
namespace Componentes
{
    Movimento::Movimento(const float vel,const float pulo,bool recuperar,const float recuperacao)
    : velocidade(vel),pulo(pulo),modVelocidade(1),modPulo(1),
    deltaRecargaMods(recuperacao),recuperar(recuperar)
    {}
    void Movimento::setModPulo(float mod)
    {
        modPulo =mod;
    }
    void Movimento::setModVelocidade(float mod)
    {
        modVelocidade = mod;
    }
    const float Movimento::getVelocidade() const
    {
        return velocidade*modVelocidade;
    }
    const float Movimento::getPulo() const
    {
        return pulo*modPulo;
    }
    
    void Movimento::RecuperarMods()
    {
        if(recuperar)
        {
            modVelocidade += (1-modVelocidade)*(deltaRecargaMods*Tempo::getDeltaTempoControlado());
            modPulo += (1-modPulo)*(deltaRecargaMods*Tempo::getDeltaTempoControlado());
        }
            

    }
}