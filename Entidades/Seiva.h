#pragma once
#include "Posicao.h"
#include "Vida.h"
#include "commons.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"
#include "ControleSeiva.h"

namespace Entidades
{
    const static string TAG_Seiva = "seiva";
    class Seiva: public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleSeiva* cS;
            Vida* vd;
            Texture texturaseiva;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Seiva(Vector2f posicao = Vector2f(0,0)):
            Entidade("Seiva"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(nullptr),
            cR(new CorpoRigido(false,false,false)),
            cS(new ControleSeiva()),
            vd(new Vida(1))
            {
                texturaseiva.loadFromFile("Arquivos/Imagens/seiva.png");
                gS = new GraficoSprite(&texturaseiva,0,false);
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cS));
                this->addComponente(static_cast<Componente*> (vd));
            }
        
    };
}