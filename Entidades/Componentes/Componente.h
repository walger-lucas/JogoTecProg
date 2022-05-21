/**
 * Jogo TecProg
 */


#ifndef _COMPONENTE_H
#define _COMPONENTE_H
namespace Entidades
{
    class Entidade;
}
using namespace Entidades;
namespace Componentes{
class Componente {
	friend Entidades::Entidade;
public: 

	virtual void setAtivado(bool atv);
	const bool getAtivado() const;
	
	Entidade* getEntidade();
	
	Componente();
	virtual ~Componente();
protected: 
	
	virtual void Atualizar() {};
	
	virtual void AtualizarFixo() {};
	
	virtual void Iniciar()=0;
	
	virtual void Render() {};
	
private: 
	Entidade* entidade;
	bool ativado;
	void setEntidade(Entidade* ent);
};
}
#endif //_COMPONENTE_H
