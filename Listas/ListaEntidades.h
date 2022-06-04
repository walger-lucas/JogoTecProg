#pragma once
#include "commons.h"
#include "Entidade.h"
using namespace std;
using namespace Entidades;

namespace Listas
{
    class ListaEntidade
    {
    private:
        list<Entidade*> lista;
        list<Entidade*>::iterator it;
        list<Entidade*>::const_iterator cIt;
        bool ativo;

    public:
        ListaEntidade();
        ~ListaEntidade();

        void Adicionar(Entidade* ent);
        void Descarregar();
        void AtualizarFixo();
        void Atualizar();
        Entidade* getEntidade(const string& nome);
        void Render();
    };
}