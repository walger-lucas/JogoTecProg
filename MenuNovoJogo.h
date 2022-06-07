#pragma once
#include "Menu.h"
#include "BotaoEntidade.h"

namespace Menus
{
    class MenuNovoJogo: public Menu
    {
        private:
            BotaoEntidade *umJog, *doisJog, *cena1, *cena2,*comecar,*voltar;
            int cenaComecar=1;
            bool inicio=false;
            Texture botaoDesapertado,botaoApertado;
            void UmJogador();
            void DoisJogadores();
            void Cena1();
            void Cena2();
            void Comecar();
            void Voltar();
            void Iniciar();
            void Atualizar();
        public:
            MenuNovoJogo();
            ~MenuNovoJogo();
    };
}