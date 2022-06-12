#pragma once
#include "Personagem.h"

namespace Entidades
{
    class Inimigo: public Personagem
    {
        public:
            Inimigo(string nome = ""):
            Personagem(nome)
            { };

            virtual ~Inimigo() {};
    };
}