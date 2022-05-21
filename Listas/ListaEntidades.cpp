#include "ListaEntidades.h"
using namespace std;
using namespace Entidades;

namespace Listas
{
    ListaEntidade::ListaEntidade():
    lista(),
    it(),
    cIt()
    { lista.clear(); }

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
        {
            lista.push_back(ent);
            ent->Iniciar();
        }
    }

    void ListaEntidade::Descarregar()
    {
        for(it = lista.begin(); it != lista.end(); it++)
        {
            if(*it)
                delete *it;
            *it = NULL;
        }
        lista.clear();
    }

    void ListaEntidade::AtualizarFixo()
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt && !(*cIt)->getDestruir())
                (*cIt)->AtualizarFixo();
    }

    void ListaEntidade::Atualizar()
    {
        int tam = (int) lista.size();
        it = lista.begin();
        for(int i = 0; i < tam; i++)
        {
            if(*it)
            {
                if((*it)->getDestruir())
                {
                    delete (*it);
                    (*it) = NULL;
                    lista.erase(it);
                    i++;
                }
                else
                    (*it)->Atualizar();
            }
        }
    }

    Entidade* ListaEntidade::getEntidade(string& nome)
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt && !(*cIt)->getDestruir() && nome == (*cIt)->getNome())
                return *cIt;
        return NULL;
    }

    void ListaEntidade::Render()
    {
        for(cIt = lista.begin(); cIt != lista.end(); cIt++)
            if(*cIt && !(*cIt)->getDestruir())
                (*cIt)->Render();
    }
}