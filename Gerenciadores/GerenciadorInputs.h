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
            static string inputText;
        public:
            static const Vector2f getMouseGlobalPos();
            static const Vector2f getMouseUIPos();
            static const bool isMouseNaTela();
            static void cleanInputText();
            static const string getInputText(int tam);
            static const string& getInputText();
            static void addBotao(EventoBotao* botao);
            static void removeBotao(EventoBotao* bot);
            static void FinalizarJogo();
            void PollEvents();
            void setWindowAtual(RenderWindow* rW);
            GerenciadorInputs(){
            }
            ~GerenciadorInputs(){};
    };
    
}