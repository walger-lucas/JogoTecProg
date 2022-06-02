#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

class MenuPrincipal: public Menu
{
    private:
        BotaoEntidade* nvJogo, *carJogo,*sair,*leaderBoard;
        bool nvJ;
        void NovoJogo();
        void CarregarOutroJogo();
        void LeaderBoard();
        void Sair();
        void Iniciar();
    public:
        MenuPrincipal()
        :nvJogo(nullptr),carJogo(nullptr),sair(nullptr),leaderBoard(nullptr),nvJ(false)
        {}
        ~MenuPrincipal();
    
};