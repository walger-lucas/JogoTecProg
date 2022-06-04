#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"ControleAndador.h"
#include "Cena.h"
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
            Texture texturaAndador;
            static list<Andador*> andadores;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);

        public:
            void Carregar();
            Andador(Vector2f posicao = Vector2f(0,0));
            ~Andador();
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
        
    };
}