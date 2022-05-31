#include "GerenciadorCenas.h"
#include "CenaTeste.h"
#include "Menu.h"
using namespace std;
using namespace Cenas;

namespace Gerenciadores
{
    int GerenciadorCenas::proxCena = -1;
    void GerenciadorCenas::setCena(const int cena)
    {


        if(cenaAtual>=0 && cenaAtual<MAXCENAS)
        {
            cenas[cenaAtual]->Descarregar();
        }
        if(cena>=0 && cena<MAXCENAS)
        {  
            cenaAtual = cena;
            cenas[cenaAtual]->Carregar();  
        }
    }

    void GerenciadorCenas::Atualizar()
    { 
        if(cenaAtual>=0 && cenaAtual<MAXCENAS) 
            cenas[cenaAtual]->Atualizar();
        if(proxCena!=cenaAtual)
        {
            setCena(proxCena);
        }
    }
    void GerenciadorCenas::ProximaCena(int id)
    {
        proxCena=id;
    }
    void GerenciadorCenas::AtualizarFixo()
    { 
        if(cenaAtual>=0 && cenaAtual<MAXCENAS) 
            cenas[cenaAtual]->AtualizarFixo();
    }

    void GerenciadorCenas::Render()
    { 
        if(cenaAtual>=0 && cenaAtual<MAXCENAS) 
            cenas[cenaAtual]->Render();
    }

    GerenciadorCenas::GerenciadorCenas():
    cenaAtual(-1)
    {
        cenas[0]= new CenaTeste(this);
        //cenas[0]= new Menu(this);
        //cenas[2]= new Cena();
        
    }

    GerenciadorCenas::~GerenciadorCenas()
    {
        int i;
        for(i=0;i<MAXCENAS;i++)
            delete cenas[i];
    }
}