#pragma once
#include "Posicao.h"
#include "Vida.h"
#include "commons.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"
#include "ControleTrampolim.h"

namespace Entidades
{
    const static string TAG_Trampolim = "trampolim";
    class Trampolim: public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleTrampolim* cT;
            Vida* vd;
            Texture texturatrampolim;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Trampolim(Vector2f posicao = Vector2f(0,0)):
            Entidade("Trampolim"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(nullptr),
            cR(new CorpoRigido(true,true,true)),
            cT(new ControleTrampolim()),
            vd(new Vida(1))
            {
                texturatrampolim.loadFromFile("Arquivos/Imagens/trampolim.png");
                pos->setEscala(Vector2f(0.5,0.5));
                gS = new GraficoSprite(&texturatrampolim,1,false);
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cT));
                this->addComponente(static_cast<Componente*> (vd));
            }
        
    };
}