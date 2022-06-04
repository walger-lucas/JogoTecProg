#pragma once
#include "Cena.h"

namespace Cenas
{
    class CenaTeste: public Cena
    {
        private:
            void apt();
            void dapt();
            void Carregar();
        public:
            CenaTeste(GerenciadorCenas* ger):
            Cena(ger)
            {}
    };

}