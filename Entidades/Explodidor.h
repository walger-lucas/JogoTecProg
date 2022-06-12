#pragma once
#include"Inimigo.h"
#include"ControleExplodidor.h"
namespace Entidades
{
    class Explodidor: public Inimigo{

        
        private:
            ControleExplodidor* cE;
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