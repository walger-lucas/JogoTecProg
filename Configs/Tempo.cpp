#include "Tempo.h"
using namespace std;

/*
    Confirmar os cálculos e uso com o Fps
    @HBWho @walger-lucas
*/

namespace Configs
{
    double Tempo::deltaTempo = 0;
    double Tempo::deltaTempoRender = 0;
    const double Tempo::getDeltaTempoFixo = 0;

    void Tempo::atualizaDeltaTempo()
    {
        tempoFinal = chorno::steady_clock::now();
        deltaTempo = static_cast<double>(tempoFinal - tempoInicio); 
        tempoInicio = chorno::steady_clock::now();
    }

    const double Tempo::getDeltaTempo()
    { return deltaTempo; }

    const double Tempo::getDeltaTempoFixo()
    { return deltaTempoFixo; }

    const double Tempo::getTempoRender()
    { return deltaTempoRender; }

    const int Tempo::getFps()
    {   }

    void Tempo::setFps(const int fps)
    {   }

    Tempo():
    tempoInicio(chrono::steady_clock::now()),
    tempoFinal(chrono::steady_clock::now())
    {   }

    ~Tempo() {  }
}
