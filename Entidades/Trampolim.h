#pragma once
#include "Obstaculo.h"
#include "ControleTrampolim.h"

namespace Entidades
{
    const static string TAG_Trampolim = "trampolim";
    class Trampolim: public Obstaculo
    {
        private:
            ControleTrampolim* cT;
            static list<Trampolim*> trampolins;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);

        public:
            void Carregar();
            Trampolim(Vector2f posicao = Vector2f(0,0));
            ~Trampolim();
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
        
    };
}