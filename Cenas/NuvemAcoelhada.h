#pragma once
#include "Cena.h"
#include "Portal.h"
namespace Cenas
{
    class NuvemAcoelhada: public Cena
    {
        private:
            void Carregar();
            void PortalFunc();
            static Portal* portal;
        public:
            static void AbrirPortal();
            NuvemAcoelhada(GerenciadorCenas* ger):
            Cena(ger)
            {}
            ~NuvemAcoelhada()
            {}

    };

}