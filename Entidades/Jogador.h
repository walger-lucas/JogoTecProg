#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"GerenciadorArquivos.h"
using namespace Entidades;
class Jogador: public Entidade{
    string txt;
    bool ui;
    public:
        void Carregar(){
            Posicao* pPos = new Posicao(0,0);
            this->addComponente(static_cast<Componente*> (pPos));
            this->addComponente(static_cast<Componente*>(new Vida(100)));
            this->addComponente(static_cast<Componente*> (new GraficoSprite(GerenciadorArquivos::getTextura(txt),0,ui)));
            this->addComponente(static_cast<Componente*> (new CorpoRigido(true,true,true)));

        }
        Jogador(string nome ="",string text ="cubo",bool ui = false): Entidade(nullptr,nome){
            txt=text;
            this->ui=ui;
        }
    
};