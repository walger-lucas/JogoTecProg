#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

class MenuPlacar: public Menu
{
    private:
        BotaoEntidade *voltarMenu,*baixo,*cima;
        Vector2f pos;
        Font arial;
        ImgTexto *placar;
        int pagina;
        void VoltarMenu();
        void Iniciar();
        void Cima();
        void Baixo();
    public:
        MenuPlacar()
        :voltarMenu(nullptr),baixo(nullptr),cima(nullptr),placar(nullptr),pagina(0)
        {}
        ~MenuPlacar();
    
};