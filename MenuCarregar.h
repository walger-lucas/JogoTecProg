#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

class MenuCarregar: public Menu
{
    private:
        BotaoEntidade* carregar,*voltar,*saves[5]={nullptr};
        Texture botaoApertado,botaoDesapertado;
        int save=-1;
        bool nomeApertado;
        void Voltar();
        void Carregar();
        void Save0();
        void Save1();
        void Save2();
        void Save3();
        void Save4();
        void Save(int id);
        void Iniciar();
    public:
        MenuCarregar()
        :carregar(nullptr),voltar(nullptr),
        nomeApertado(false)
        {
            botaoApertado.loadFromFile("Arquivos/Imagens/buttonA.png");
            botaoDesapertado.loadFromFile("Arquivos/Imagens/buttonB.png");
        }
        ~MenuCarregar();
    
};