#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"ControleJogador.h"
namespace Entidades
{
    const static string TAG_JOGADOR = "jogador";
    
    class Jogador: public Entidade{

        
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleJogador* cJ;
            Texture texturaJimmy;

        public:
            void Carregar(){
                Vector2f dim = gS->getSprite()->getDim();
                Vector2f esc =gS->getSprite()->getEscala();
                cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

            }
            Jogador(Vector2f posicao = Vector2f(0,0))
            : Entidade("Jogador"),
            pos(new Posicao(posicao.x,posicao.y)),
            gS(nullptr),
            cR(new CorpoRigido(true,true,true)),
            cJ(new ControleJogador())
            {
                
                texturaJimmy.loadFromFile("Arquivos/Imagens/Jimmy.png");
                gS=new GraficoSprite(&texturaJimmy,1,false);
                this->addComponente(static_cast<Componente*> (pos));
                this->addComponente(static_cast<Componente*> (gS));
                this->addComponente(static_cast<Componente*> (cR));
                this->addComponente(static_cast<Componente*> (cJ));
            }
        
    };
}