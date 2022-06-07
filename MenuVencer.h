#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

namespace Menus
{
    class MenuVencer: public Menu
    {
        private:
            BotaoEntidade *nomeB,*menu,*lider;
            Texture botaoApertado,botaoDesapertado;
            string nome;
            bool nomeApertado;
            void VoltaMenu();   
            void Nome();
            void Lider();
            void Iniciar();
            void Atualizar();
        public:
            MenuVencer()
            :nomeB(nullptr),menu(nullptr),lider(nullptr),
            nome(""),nomeApertado(false)
            {
                botaoApertado.loadFromFile("Arquivos/Imagens/buttonA.png");
                botaoDesapertado.loadFromFile("Arquivos/Imagens/buttonB.png");
            }
            ~MenuVencer();
        
    };
}