#pragma once
#include "Posicao.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"

namespace Entidades
{
    class Obstaculo: public Entidade
    {
    protected:
        Posicao* pos;
        CorpoRigido* cR;
        GraficoSprite* gS;
        Texture textura;
    public:
        Obstaculo(string nome = ""):
        Entidade(nome),
        pos(nullptr),
        cR(nullptr),
        gS(nullptr),
        textura()
        {}
        virtual ~Obstaculo()
        {
            pos = nullptr;
            cR = nullptr;
            gS = nullptr;
        }
    };
}