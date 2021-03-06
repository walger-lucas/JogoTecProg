#pragma once
#include"Personagem.h"
#include"ControleJogador.h"
namespace Entidades
{
    
    
    class Jogador: public Personagem{

        
        private:
            ControleJogador* cJ;
            bool jimmy;
            static bool doisJogadores;
            static int pontuacao;
            static Jogador* Jimmy;
            static Jogador* Janny;
            static int vidaJimmy,vidaJanny;
        public:
            const static string TAG_JOGADOR;
            static Vector2f localizacaoJogadorProximo(const Vector2f posAtual);
            static void salvarVidas();
            static void resetarVidas();
            static int getVidas(int i);
            static Vector2f localizacaoMediaJogadores();
            static void darPontos(int pontos);
            static void zerarPontos();
            static int getPontos();
            static bool SaoDoisJogadores();
            static bool JogadoresProximos();
            static void setDoisJogadores(bool doisJog);
            static int vidasJogador(int i);
            static bool JogadoresVivos();
            static void escreverDados(ofstream& stream);
            static void lerDados(ifstream& stream,Cena* cena);
            void Carregar();
            Jogador(Vector2f posicao = Vector2f(0,0),bool Jimmy=true,int vidas=4);
            ~Jogador();
            
        
    };
}