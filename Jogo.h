#pragma once
#include "Gerenciadores.h"
#include "commons.h"
#include "Tempo.h"
#include "Menu.h"
#include "Salvador.h"
using namespace Gerenciadores;
using namespace Configs;
using namespace Menus;
class Jogo
{
    private:
        private:
        RenderWindow* window;
        Tempo tempo;
        GerenciadorGrafico render;
        GerenciadorCenas gerCenas;
        GerenciadorInputs gerInput;
        GerenciadorColisoes fisica;
        float tempoUltAtualizacaoFisica;
        float tempoUltRender;
        const int atualizacaoMax;
        static Menu* menuAtual;
        static Menu* proxMenu;
        Salvador salvador;
        Lideranca lideranca;
    public:
        static void MenuAtual(Menu* menu);
        ~Jogo();
        Jogo();
        void Loop();
};
