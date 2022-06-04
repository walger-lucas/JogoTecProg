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
            Texture texturaExplodidor;
            static list<Explodidor*> explodidores;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);

        public:
            void Carregar();
            Explodidor(Vector2f posicao = Vector2f(0,0));
            ~Explodidor();
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
        
    };
}