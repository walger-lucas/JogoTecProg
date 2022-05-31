#pragma once
#include "Gerenciadores.h"
#include "commons.h"
#include "Tempo.h"
using namespace Gerenciadores;
using namespace Configs;
class Jogo
{
    private:
        private:
        RenderWindow* window;
        Tempo tempo;
        float tempoUltAtualizacaoFisica;
        float tempoUltRender;
        const int atualizacaoMax;
    public:
        ~Jogo();
        Jogo();
        void Loop();
};
