#pragma once
#include "Posicao.h"
#include "Vida.h"
#include "commons.h"
#include "GraficoSprite.h"
#include "Entidade.h"
#include "CorpoRigido.h"
#include "ControleSeiva.h"

namespace Entidades
{
    const static string TAG_Seiva = "seiva";
    class Seiva: public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleSeiva* cS;
            Vida* vd;
            Texture texturaSeiva;
            static list<Seiva*> seivas;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);
        public:
            void Carregar();
            Seiva(Vector2f posicao = Vector2f(0,0));
            ~Seiva();
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
        
    };
}