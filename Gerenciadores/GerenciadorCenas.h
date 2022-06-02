#pragma once
#include "commons.h"
#include "Cena.h"
using namespace std;
using namespace Cenas;

#define MAXCENAS 1

namespace Gerenciadores
{
    class GerenciadorCenas
    {
    private:
        Cena* cenas[MAXCENAS];
        static int cenaAtual;
        static int proxCena;

    public:
        void setCena(const int cena);
        void Atualizar();
        void AtualizarFixo();
        void Render();
        static const int getCenaAtual();
        static void ProximaCena(int id);

        GerenciadorCenas();
        ~GerenciadorCenas();
    };
    
}