#pragma once
#include "Cena.h"
#include "Portal.h"
namespace Cenas
{
    class PlanicieAcoelhada: public Cena
    {
        private:
            void Carregar();
            void PortalFunc();
        public:
            PlanicieAcoelhada(GerenciadorCenas* ger):
            Cena(ger)
            {}
            ~PlanicieAcoelhada()
            {}

    };

}