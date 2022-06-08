#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

namespace Menus
{
    class MenuMorte: public Menu
    {
        private:
            BotaoEntidade *voltarMenu;
            Vector2f pos;
            Font guest3D;
            ImgTexto *textoGameOver;
            void VoltarMenu();
            void Iniciar();
        public:
            MenuMorte()
            :voltarMenu(nullptr)
            {}
            ~MenuMorte();
        
    };
}