#pragma once

#include "commons.h"
#include "ListaEntidades.h"
using namespace Listas;
using namespace std;

class GerenciadorCenas;

/*
    Realizei uma sobrecarga de operadores += para adicionar elementos na lista
    e [] para acessar elementos com "index" o nome
    @HBWho @walger-lucas
*/

namespace Cenas
{
    class Cena
    {
    private:
        GerenciadorCenas* gerenciador;
        ListaEntidade lista;


        void Descarregar();
        void Atualizar();
        void AtualizarFixo();
        void Render();

        void iniciar();

    public:
        Cena(GerenciadorCenas* ger = NULL);
        virtual ~Cena();

        void MudaCena(const int cena);
        void AdicionarEntidade(Entidade* ent);
        Entidade* getEntidade(string& nome);

        void operator+=(Entidade* ent);
        Entidade* operator[](string& nome)

    protected:
        virtual void Carregar();
        
    }
}