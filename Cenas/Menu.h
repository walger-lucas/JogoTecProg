#pragma once
#include "Cena.h"
namespace Cenas
{
    class Menu: public Cena
    {
        private:
            void novoJogo();
            void CenaUm();
            void CenaDois();
            void UmJogador();
            void DoisJogadores();
            void carregarJogoAntigo();
            void leaderBoard();
            void sair();
            void voltar();
            void Carregar();
        public:
            Menu(GerenciadorCenas* ger=nullptr)
            :Cena(ger){}
            ~Menu()
            {}
    };
}