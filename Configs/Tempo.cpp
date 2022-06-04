#include "Tempo.h"
using namespace std;
using namespace chrono;

namespace Configs
{
    double Tempo::deltaTempo = 0;
    bool Tempo::pause(false);
    double Tempo::deltaTempoRender = (float) 1.0/60.0;
    const double Tempo::deltaTempoFixo = (float) 1.0/80.0;

    void Tempo::atualizaDeltaTempo()
    {
        tempoFinal = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(tempoFinal - tempoInicio);
        deltaTempo = static_cast<double>(time_span.count()); 
        tempoInicio = steady_clock::now();
    }

    const double Tempo::getDeltaTempo()
    { return deltaTempo; }
    const double Tempo::getDeltaTempoControlado()
    { return (pause)?0:deltaTempo; }

    const double Tempo::getDeltaTempoFixo()
    { return deltaTempoFixo; }

    const double Tempo::getTempoRender()
    { return deltaTempoRender; }

    const int Tempo::getFps()
    { return (int) ((1/deltaTempoRender) + 0.5); }

    void Tempo::setFps(const int fps)
    {
        if(fps > 0)
            deltaTempoRender = (float) 1.0/fps;
    }    

    Tempo::Tempo()
    {
        tempoInicio = steady_clock::now();
        tempoFinal = steady_clock::now();
    }

    Tempo::~Tempo() {  }
    void Tempo::Pausar(bool ps)
    {
        pause = ps;
    }
    const bool Tempo::Pausado()
    {
        return pause;
    }
}
