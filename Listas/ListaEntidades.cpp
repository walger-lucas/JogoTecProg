#include "ListaEntidades.h"
#include "Entidade.h"
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
        ativo = true;
        if(ent)
        {
            lista.push_back(ent);
            ent->Iniciar();
        }
    }

    void ListaEntidade::Descarregar()
    {
        ativo = false;
        for(it = lista.begin(); it != lista.end(); it++)
        {
            if(*it)
                delete *it;
            *it = nullptr;
        }
        lista.clear();
    }

    void ListaEntidade::AtualizarFixo()
    {
        for(cIt = lista.begin();ativo&& cIt != lista.end(); cIt++)
        {
            if(*cIt && !(*cIt)->getDestruir())
                (*cIt)->AtualizarFixo();

            if(!ativo)
            {
                break;
            }
                
        }
    }

    void ListaEntidade::Atualizar()
    {
        it = lista.begin();
        while(it!=lista.end()&&ativo)
        {
            if(*it)
            {                
                if((*it)->getDestruir())
                {
                    delete (*it);
                    (*it) = NULL;
                    lista.erase(it++);
                    
                }
                else
                {
                    (*it)->Atualizar();
                    if(!ativo)
                    {
                        break;
                    }
                        
                    it++;
                }

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
        for(cIt = lista.begin(); ativo && cIt != lista.end(); cIt++)
        {
            if(*cIt && !(*cIt)->getDestruir())
                (*cIt)->Render();
            if(!ativo)
                break;
        }

    }
}