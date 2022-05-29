#include "GerenciadorCenas.h"
#include "CenaTeste.h"
using namespace std;
using namespace Cenas;

namespace Gerenciadores
{
    void GerenciadorCenas::setCena(const int cena)
    {
        if(cena>=0 && cena<=MAXCENAS)
        {   
            if(cenaAtual>=0 && cenaAtual<MAXCENAS)
            {
                cenas[cenaAtual]->Descarregar();
            }
            cenaAtual = cena;
            cenas[cenaAtual]->Carregar();  
        }
        else
        {
            cout<< "Esta cena nao existe!\n";
        }
    }

    void GerenciadorCenas::Atualizar()
    { cenas[cenaAtual]->Atualizar(); }

    void GerenciadorCenas::AtualizarFixo()
    { cenas[cenaAtual]->AtualizarFixo(); }

    void GerenciadorCenas::Render()
    { cenas[cenaAtual]->Render(); }

    GerenciadorCenas::GerenciadorCenas():
    cenaAtual(-1)
    {
        cenas[0]= new CenaTeste(this);
        /*cenas[1]= new Cena();
        cenas[2]= new Cena();
        */
    }

    GerenciadorCenas::~GerenciadorCenas()
    {
        int i;
        for(i=0;i<MAXCENAS;i++)
            delete cenas[i];
    }
}