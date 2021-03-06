#pragma once

#include "commons.h"
#include <chrono>
using namespace std;

namespace Configs
{
    class Tempo
    {
    private:
        chrono::time_point<chrono::steady_clock> tempoInicio, tempoFinal;
        static bool pause;
        static double deltaTempo, deltaTempoRender;
        static const double deltaTempoFixo;

    public:
        void atualizaDeltaTempo();
        static const double getDeltaTempoControlado(); 
        static const double getDeltaTempo();
        static const double getDeltaTempoFixo();
        static const double getTempoRender();
        static void Pausar(bool pause);
        static const bool Pausado();

        static const int getFps();
        static void setFps(const int fps);

        Tempo();
        ~Tempo();
    };
}