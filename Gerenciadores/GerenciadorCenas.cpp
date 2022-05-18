#include "GerenciadorCenas.h"
using namespace std;
using namespace Cenas;

namespace Gerenciadores
{
    void GerenciadorCenas::setCena(const int cena)
    {
        if(cena >= 0 && cena < cenaMax)
        {
            cenas[cenaAtual]->Descarregar();
            cenaAtual = cena;
            emCena = true;
        }
    }

    void GerenciadorCenas::Atualizar()
    { cenas[cenaAtual]->Atualizar(); }

    void GerenciadorCenas::AtualizarFixo()
    { cenas[cenaAtual]->AtualizarFixo(); }

    void GerenciadorCenas::Render()
    { cenas[cenaAtual]->Render(); }

    GerenciadorCenas::GerenciadorCenas():
    cenaAtual(-1),
    cenaMax(MAXCENAS),
    emCena(false)
    {
        //cenas[i] = static_cast<Cena*>();
    }

    GerenciadorCenas::~GerenciadorCenas()
    {
        //delete[] cenas;
    }
}