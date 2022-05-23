#include "Cena.h"
#include "GerenciadorCenas.h"
#include "Entidade.h"
using namespace std;
using namespace Gerenciadores;

namespace Cenas
{
    void Cena::Descarregar()
    { lista.Descarregar(); }

    void Cena::Atualizar()
    { lista.Atualizar(); }

    void Cena::AtualizarFixo()
    { lista.AtualizarFixo(); }

    void Cena::Render()
    { lista.Render(); }

    Cena::Cena(GerenciadorCenas* ger):
    gerenciador(ger),
    lista()
    {}

    Cena::~Cena()
    { gerenciador = NULL; }

    void Cena::MudarCena(const int cena)
    {
        if(gerenciador)
        {
            gerenciador->setCena(cena);
        }
    }

    void Cena::AdicionarEntidade(Entidade* ent)
    { 
        if(ent!=nullptr)
        {
            lista.Adicionar(ent); 
            ent->setCena(this);
        }
        
    }

    Entidade* Cena::getEntidade(string& nome)
    { return lista.getEntidade(nome); }

    void Cena::operator+=(Entidade* ent)
    { AdicionarEntidade(ent); }

    Entidade* Cena::operator[](string& nome)
    { return getEntidade(nome); }
}