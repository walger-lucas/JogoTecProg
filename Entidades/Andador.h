#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"GerenciadorArquivos.h"
#include"ControleAndador.h"
namespace Entidades
{
    const static string TAG_ANDADOR = "andador";
    class Andador: public Entidade{

        
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleAndador* cA;
            Vida* vd;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Andador(Vector2f posicao = Vector2f(0,0))
            : Entidade("Andador"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(new GraficoSprite(GerenciadorArquivos::getTextura("cubo"),0,false)),
            cR(new CorpoRigido(true,true,true)),
            cA(new ControleAndador()),
            vd(new Vida(1))
            {
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cA));
                this->addComponente(static_cast<Componente*> (vd));
            }
        
    };
}