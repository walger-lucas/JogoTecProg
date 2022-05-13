#include "Cena.h"
#include "GerenciadorCenas.h"
using namespace std;
using namespace Gerenciadores;

/*
    Carregar; Iniciar; MudarCena 
    Confirmar uso das funções
    @HBWho @walger-lucas
*/

namespace Cenas
{
    void Cenas::Carregar()
    {

    }

    void Cena::Descarregar()
    { lista.Descarregar(); }

    void Cena::Atualizar()
    { lista.Atualizar(); }

    void Cena::AtualizarFixo()
    { lista.AtualizarFixo(); }

    void Render() const
    { lista.Render(); }

    void Cena::Iniciar()
    {

    }

    Cena::Cena(GerenciaadorCenas* ger):
    gerenciador(ger),
    lista()
    {}

    Cena::~Cena()
    { ger = NULL; }

    void Cena::MudarCena(const int cena)
    {

    }

    void Cena::AdicionarEntidade(Entidade* ent)
    { lista.Adicionar(ent) }

    Entidade* Cena::getEntidade(string& nome) const
    { return lista.getEntidade(nome); }

    void Cena::operator+=(Entidade* ent)
    { AdicionarEntidade(ent); }

    Entidade* Cena::operator[](string& nome)
    { return getEntidade(nome); }
}