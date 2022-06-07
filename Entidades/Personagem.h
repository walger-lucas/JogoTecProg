#pragma once
#include "Posicao.h"
#include "Vida.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"

namespace Entidades
{
    class Personagem: public Entidade
    {
        protected:
            Vida* vd;
            Posicao* pos;
            CorpoRigido* cR;
            GraficoSprite* gS;
            Texture textura;
        public:
            Personagem(string nome = ""):
            Entidade(nome),
            vd(nullptr),
            pos(nullptr),
            cR(nullptr),
            gS(nullptr),
            textura()
            {};

            virtual ~Personagem()
            {
                vd = nullptr;
                pos = nullptr;
                cR = nullptr;
                gS = nullptr;
            };

    };
}