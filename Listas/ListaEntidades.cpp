#include "ListaEntidades.h"
using namespace std;
using namespace Entidades;

/*
    Verificar a função Descarregar
    @HBWho @walger-lucas
*/

namespace Listas
{
    ListaEntidade::ListaEntidade():
    lista(),
    it(),
    cIt()
    { lista. clear(); }

    ListaEntidade::~ListaEntidade()
    {
        for(it = lista.begin(); it != lista.end(); it++)
            {
                if(*it)
                    delete *it;
                *it = NULL;
            }
        lista.clear();
    }

    void ListaEntidade::Adicionar(Entidade* ent)
    {
        if(ent)
            lista.push_back(ent);
    }

    void ListaEntidade::Descarregar()
    {
        int tam = (int) lista.size();
        it = lista.begin();

        for(int i = 0; i < tam ; i++)
        {
            if(*it && (*it).getDestruir())
            {
                delete *it;
                *it = NULL;
                lista.erase(it);
                i++;
            }
            it++;
        }
    }

    void ListaEntidade::AtualizarFixo() const
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt)
                (*cIt).AtualizarFixo();
    }

    void ListaEntidade::Atualizar() const
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt)
                (*cIt).Atualizar();
    }

    Elemento* ListaEntidade::getEntidade(string& nome) const
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt)
                if(nome == (*cIt).getNome)
                    return *cIt;
        return NULL;
    }

    void ListaEntidade::Render() const
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt)
                (*cIt).Render();
    }
}