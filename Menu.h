#pragma once
#include "Ente.h"
#include "ListaEntidades.h"

namespace Menus
{
    class Menu: public Ente
    {
        protected:
            Listas::ListaEntidade entidades;
            virtual void Atualizacoes(){};
        public:
            virtual void Iniciar()=0;
            void Atualizar()
            {
                entidades.Atualizar();
                Atualizacoes();
            };
            void AtualizarFixo(){};
            void Render(){};
            virtual ~Menu()
            {
                entidades.Descarregar();
            }
            Menu()
            {}
    };
}