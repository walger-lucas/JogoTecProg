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
		friend class Listas::ListaEntidade;
	private: 

		vector<Componente*> componentes;
		vector<string> tags;
		string nome;
		bool destruir;
		bool ativo;
		Cena* cena;

		
		void Atualizar();
		void Render();


		

	public: 
		void Iniciar();
		void AtualizarFixo();
		void setCena(Cena* cena);
		//testa componentes para o tipo e os converte com downcast caso encontrado o do TIPO.
		template<class TIPO> 
		TIPO* getComponente()
		{
			int i;
			int size = componentes.size();
			type_index t (typeid(TIPO));
			for(i=0;i<size;i++)
			{
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
			Entidade(string nome = "");
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
	//tag significativa de chao
	const static string TAG_GROUND= "ground";
}
#endif //_ENTIDADE_H