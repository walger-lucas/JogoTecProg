/**
 * Jogo TecProg
 */


#include "Componente.h"


using namespace Entidades;
namespace Componentes{
    /**
     * seta ativado.
     */
    void Componente::setAtivado(bool atv)
    {
        this->ativado = atv;
    }

    /**
     * retorna entidade de pertencimento do componente
     */
    Entidade* Componente::getEntidade() {
        return entidade;
    }

    /**
     * Construtor
     */
    Componente::Componente()
    : entidade(nullptr) {}
    

    /**
     * Destructor
     */
    Componente::~Componente() {
        
    }

    void Componente::setEntidade(Entidade* ent)	{
		entidade = ent;
	}
}