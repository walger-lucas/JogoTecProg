#pragma once
#include"commons.h"
using namespace std;
using namespace sf;
namespace Gerenciadores
{
    class EventoBotao;

    class GerenciadorInputs
    {
        private:
            static RenderWindow* window;
            Event evento;
            static list<EventoBotao*> botoes;
        public:
            static const Vector2f getMouseGlobalPos();
            static const Vector2f getMouseUIPos();
            static const bool isMouseNaTela();
            static void addBotao(EventoBotao* botao);
            static void removeBotao(EventoBotao* bot);
            void PollEvents();
            void setWindowAtual(RenderWindow* rW);
            GerenciadorInputs(){}
            ~GerenciadorInputs(){};
    };
    
}