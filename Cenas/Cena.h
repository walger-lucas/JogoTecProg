#pragma once

#include "commons.h"
#include "ListaEntidades.h"
#include "Ente.h"
using namespace Listas;
using namespace std;

namespace Gerenciadores
{
    class GerenciadorCenas;
}

using namespace Gerenciadores;

namespace Cenas
{
    class Cena: public Ente
    {
    private:
        GerenciadorCenas* gerenciador;
        ListaEntidade lista;

        void Descarregar();
        void Atualizar();
        void AtualizarFixo();
        void Render();

        friend class Gerenciadores::GerenciadorCenas;

    public:
        Cena(GerenciadorCenas* ger = NULL);
        virtual ~Cena();

        //Apenas utilizavel em Atualizar.
        void MudarCena(const int cena);
        void AdicionarEntidade(Entidade* ent);
        Entidade* getEntidade(const string& nome);

        void operator+=(Entidade* ent);
        Entidade* operator[](const string& nome);

    protected:
        virtual void Carregar() = 0;
        
    };
}