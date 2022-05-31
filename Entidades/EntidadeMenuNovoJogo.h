#pragma once
#include "Entidade.h"
#include "ControleMenuNovoJogo.h"
namespace Entidades
{
    class EntidadeMenuNovoJogo: public Entidade
    {
        private:
            void Carregar()
            {}
        public:
            EntidadeMenuNovoJogo()
            {
                addComponente(new ControleMenuNovoJogo());
            }
            ~EntidadeMenuNovoJogo(){}
    };
}