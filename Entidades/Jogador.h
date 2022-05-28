#pragma once
#include"Posicao.h"
#include"Vida.h"
#include"commons.h"
#include"GraficoSprite.h"
#include"Entidade.h"
#include"CorpoRigido.h"
#include"ControleJogador.h"
#include"Vida.h"
namespace Entidades
{
    
    
    class Jogador: public Entidade{

        
        private:
            
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControleJogador* cJ;
            Vida* vida;
            Texture textura;
            bool jimmy;
            static Jogador* Jimmy;
            static Jogador* Janny;
        public:
            const static string TAG_JOGADOR;
            static Vector2f localizacaoJogadorProximo(const Vector2f posAtual);
            static Vector2f localizacaoMediaJogadores();
            static bool JogadoresVivos();

            void Carregar();
            Jogador(Vector2f posicao = Vector2f(0,0),bool Jimmy=true);
            ~Jogador();
            void Dano(int dano)
            {
                cout<<"Dano de "<<dano<<endl;
            }
            
        
    };
}