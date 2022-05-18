/**
 *	Jogo TecProg
 */


#ifndef _ENTIDADE_H
#define _ENTIDADE_H
#include"commons.h"
#include"Componente.h"


#define RES_TAGS 8
#define RES_COMPONENTES 8


namespace Cenas{
	class Cena;
}
namespace Listas
{
	class ListaEntidade;
}
using namespace Cenas;
using namespace Componentes;
using namespace std;

namespace Entidades{

	class Entidade {

	private: 

		vector<Componente*> componentes;
		vector<string> tags;
		string nome;
		bool destruir;
		bool ativo;
		Cena* cena;

		
		void Atualizar();
		
		void AtualizarFixo();
		
		
		
		void Render();

		friend class Listas::ListaEntidade;

	public: 
		void Iniciar();
		//testa componentes para o tipo e os converte com downcast caso encontrado o do TIPO.
		template<class TIPO> 
		TIPO* getComponente()
		{
			int i;
			int size = componentes.size();
			for(i=0;i<size;i++)
			{
				type_index t (typeid(TIPO));
				if(t== typeid(*(componentes[i])) )
				{
					return (dynamic_cast<TIPO*> (componentes[i]) );
				}
			}
			return nullptr;
		}
		
		void Destruir();
		
		const bool getDestruir() const;
		
		void setAtivo(bool ativo);
		
		const bool getAtivo() const;
		
		const string& getNome() const;
		
	/**
	 * testa se ha tags
	 */
		const bool temTag(const string& tag) const;
		
	/**
		* Construtor e Destrutor
		* 
	*/
		Entidade(Cena* cena = nullptr, string nome = "");
		virtual ~Entidade();
		//pega a cena atual
		Cena* getCena();

	protected: 
		
		void setNome(const string& nome);
			
		/**
		 * adiciona tags ao array
		 */
		void addTag(const string& tag);
			
		/**
		 * adiciona componentes ao array.
		 */
		void addComponente(Componente* comp);
			
			
		virtual void Carregar()=0;

	};
}
#endif //_ENTIDADE_H