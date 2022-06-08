#pragma once
#include "Obstaculo.h"
#include "ControleEspinho.h"

namespace Entidades
{
    const static string TAG_ESPINHO = "espinho";
    class Espinho: public Obstaculo
    {
        private:
            ControleEspinho* cE;
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