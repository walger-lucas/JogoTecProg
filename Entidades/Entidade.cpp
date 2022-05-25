#include "Entidade.h"
using namespace Componentes;
using namespace std;
using namespace Cenas;
namespace Entidades{
    //seta objeto para ser destruido
    void Entidade::Destruir() {
        destruir= true;
    }

    //ve se objeto deve ser destruido
    const bool Entidade::getDestruir() const {
        return destruir;
    }

    //seta a ativacao do objeto e coloca todos os seus componentes com essa ativacao.
    void Entidade::setAtivo(bool ativo) {
        this->ativo = ativo;       
        int i;
        int size = componentes.size();
        for (i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr)
                componentes[i]->setAtivado(ativo);
            else
                return;
        }

    }

    //ve a ativacao do objeto
    const bool Entidade::getAtivo() const {
        return ativo;
    }
    //ve nome do objeto
    const string& Entidade::getNome() const {
        return nome;
    }

    //ve se possui tag especifica
    const bool Entidade::temTag(const string& tag) const {
        int i;
        int size=tags.size();
        for(i=0;i<size;i++)
        {
            if(tag==tags[i])
                return true;
        }
        return false;
    }

    
    Entidade::Entidade(string nome):
    Ente(),
    nome(nome)
    {
        tags.clear();
        componentes.clear();
        tags.reserve(RES_TAGS);
        componentes.reserve(RES_COMPONENTES);
        ativo=true;
        destruir=false;
    }

    /**
     * @return Cena*
     */
    Cena* Entidade::getCena() {
        return cena;
    }

    /**
     * @param nome
     */
    void Entidade::setNome(const string& nome) {
        this->nome = nome;
    }

    /**
     * @param tag
     */
    void Entidade::addTag(const string& tag) {
        tags.push_back(tag); 
    }


    void Entidade::addComponente(Componente* comp) {
        if (comp !=nullptr)
        {
            comp->setEntidade(this);
            componentes.push_back(comp);
        }
    }

   
    Entidade::~Entidade() {

        int i;
        int size = componentes.size();
        for(i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr)
            {
                delete componentes[i];
                componentes[i]=nullptr;
            }
        }
        componentes.clear();
    }

    void Entidade::Atualizar() {
        int i;
        int size = componentes.size();
        for (i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr&& componentes[i]->getAtivado())
                componentes[i]->Atualizar();
        }
    }

    void Entidade::AtualizarFixo() {
       int i;
       int size = componentes.size();
        for (i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr&& componentes[i]->getAtivado())
                componentes[i]->AtualizarFixo();
            else
                return;
        }
    }

    void Entidade::Iniciar() {

        int i;
        int size = componentes.size();
        for (i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr)
                componentes[i]->Iniciar();
            else
                return;
        }
        Carregar();
    }

    void Entidade::Render() {
        int i;
        int size = componentes.size();
        for (i=0;i<size;i++)
        {
            if(componentes[i]!=nullptr && componentes[i]->getAtivado())
                componentes[i]->Render();
            else
                return;
        }
    }
    void Entidade::setCena(Cena* cena)
    {
        this->cena = cena;
    }
}