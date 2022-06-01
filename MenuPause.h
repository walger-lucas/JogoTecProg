#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

class MenuPause: public Menu
{
    private:
        BotaoEntidade* salvar, *voltarJogo,*voltarMenu;
        void VoltarJogo();
        void VoltarMenu();
        void Salvar();
        void Iniciar();
    public:
        MenuPause()
        :salvar(nullptr),voltarJogo(nullptr),voltarMenu(nullptr)
        {}
        ~MenuPause();
    
};