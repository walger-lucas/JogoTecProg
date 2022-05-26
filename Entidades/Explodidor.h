#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"ControleExplodidor.h"
namespace Entidades
{
    class Explodidor: public Entidade{

        
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleExplodidor* cE;
            Vida* vd;
            Texture texturaAndador;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Explodidor(Vector2f posicao = Vector2f(0,0))
            : Entidade("Andador"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(nullptr),
            cR(new CorpoRigido(true,true,true)),
            cE(new ControleExplodidor()),
            vd(new Vida(3,0.3))
            {
                texturaAndador.loadFromFile("Arquivos/Imagens/Explodidor_A.png");
                pos->setEscala(Vector2f(1.5,1.5));
                gS =new GraficoSprite(&texturaAndador,0,false);
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cE));
                this->addComponente(static_cast<Componente*> (vd));
            }
        
    };
}