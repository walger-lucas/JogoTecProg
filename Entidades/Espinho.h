#pragma once
#include "Posicao.h"
#include "Vida.h"
#include "commons.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"
#include "ControleEspinho.h"

namespace Entidades
{
    const static string TAG_ESPINHO = "espinho";
    class Espinho: public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleEspinho* cE;
            Vida* vd;
            Texture texturaespinho;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Espinho(Vector2f posicao = Vector2f(0,0)):
            Entidade("Espinho"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(nullptr),
            cR(new CorpoRigido(true,true,true)),
            cE(new ControleEspinho()),
            vd(new Vida(1))
            {
                pos->setEscala(Vector2f(0.5,0.5));
                texturaespinho.loadFromFile("Arquivos/Imagens/Espinho.png");
                gS = new GraficoSprite(&texturaespinho,1,false);
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cE));
                this->addComponente(static_cast<Componente*> (vd));
            }
        
    };
}