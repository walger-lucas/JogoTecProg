#pragma once
#include "Cena.h"
namespace Cenas
{
    class Menu: public Cena
    {
        private:
            void Carregar();
        public:
            Menu(GerenciadorCenas* ger=nullptr)
            :Cena(ger){}
            ~Menu()
            {}
    };
}