#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

class MenuPrincipal: public Menu
{
    private:
        BotaoEntidade* nvJogo, *carJogo,*sair,*leaderBoard;
        Vector2f pos;
        ImgTexto *titulo;
        Font guest3D;
        bool nvJ;
        void NovoJogo();
        void CarregarOutroJogo();
        void LeaderBoard();
        void Sair();
        void Iniciar();
    public:
        MenuPrincipal()
        :nvJogo(nullptr),carJogo(nullptr),sair(nullptr),leaderBoard(nullptr),titulo(nullptr),nvJ(false)
        {}
        ~MenuPrincipal();
    
};
