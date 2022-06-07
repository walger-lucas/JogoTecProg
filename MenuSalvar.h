#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
#include "Menu.h"

namespace Menus
{
    class MenuSalvar: public Menu
    {
        private:
            BotaoEntidade* salvar, *nomeB,*voltar,*saves[5]={nullptr};
            Texture botaoApertado,botaoDesapertado;
            string nome;
            int save=-1;
            bool nomeApertado;
            void Voltar();
            void Salvar();
            void Save0();
            void Save1();
            void Save2();
            void Save3();
            void Save4();
            void Save(int id);
            
            void Nome();
            void Iniciar();
            void Atualizar();
        public:
            MenuSalvar()
            :salvar(nullptr),nomeB(nullptr),voltar(nullptr),
            nome(""),nomeApertado(false)
            {
                botaoApertado.loadFromFile("Arquivos/Imagens/buttonA.png");
                botaoDesapertado.loadFromFile("Arquivos/Imagens/buttonB.png");
            }
            ~MenuSalvar();
        
    };
}