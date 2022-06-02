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
            static list<Espinho*> espinhos;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);

        public:
            void Carregar();
            Espinho(Vector2f posicao = Vector2f(0,0));
            ~Espinho();
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
        
    };
}