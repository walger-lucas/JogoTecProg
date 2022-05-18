#pragma once
#include "commons.h"
#include "Cena.h"
using namespace std;
using namespace Cenas;

#define MAXCENAS 3

namespace Gerenciadores
{
    class GerenciadorCenas
    {
    private:
        Cena* cenas[MAXCENAS];
        int cenaAtual;
        int cenaMax;
        bool emCena;

    public:
        void setCena(const int cena);
        void Atualizar();
        void AtualizarFixo();
        void Render();

        GerenciadorCenas();
        ~GerenciadorCenas();
    };
}