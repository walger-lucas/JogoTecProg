#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"GerenciadorArquivos.h"
#include"ControleJogador.h"
using namespace Entidades;
class Jogador: public Entidade{

    private:
        Posicao* pos;
        GraficoSprite* gS;
        CorpoRigido* cR;
        ControleJogador* cJ;

    public:
        void Carregar(){
            Vector2f dim = gS->getSprite()->getDim();
            Vector2f esc =gS->getSprite()->getEscala();
            cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

        }
        Jogador(Vector2f posicao = Vector2f(0,0))
        : Entidade("Jogador"),
        pos(new Posicao(posicao.x,posicao.y)),
        gS(new GraficoSprite(GerenciadorArquivos::getTextura("mario"),0,false)),
        cR(new CorpoRigido(true,true,true)),
        cJ(new ControleJogador())
        {
            this->addComponente(static_cast<Componente*> (pos));
            this->addComponente(static_cast<Componente*> (gS));
            this->addComponente(static_cast<Componente*> (cR));
            this->addComponente(static_cast<Componente*> (cJ));
        }
    
};