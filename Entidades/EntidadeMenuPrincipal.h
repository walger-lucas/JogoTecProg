#pragma once
#include "Entidade.h"
#include "ControleMenuPrincipal.h"
namespace Entidades
{
    class EntidadeMenuPrincipal: public Entidade
    {
        private:
            void Carregar()
            {}
        public:
            EntidadeMenuPrincipal()
            {
                addComponente(new ControleMenuPrincipal());
            }
            ~EntidadeMenuPrincipal(){}
    };
}