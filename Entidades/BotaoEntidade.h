#pragma once
#include "Entidade.h"
#include "Botao.h"
using namespace sf;
using namespace std;
using namespace Componentes;
namespace Entidades
{
    class BotaoEntidade: public Entidade
    {
        private:
            void Carregar();
        public:
            ~BotaoEntidade();
            BotaoEntidade(Vector2f pos,float tam,const string& txt, 
            Vector2f offset,const string& textura,const string& fonte,function<void()> apt,function<void()> dapt);
            
            
    };
}
