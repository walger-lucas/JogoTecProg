#pragma once
#include "Cena.h"
#include "BotaoEntidade.h"
#include "Componente.h"
namespace Componentes
{
    class ControleMenuPrincipal: public Componente
    {
        private:
            BotaoEntidade* nvJogo, *carJogo,*sair,*leaderBoard;
            bool nvJ;
            void NovoJogo();
            void CarregarOutroJogo();
            void LeaderBoard();
            void Sair();
            
            void Iniciar();
            void Atualizar();
        public:
            ControleMenuPrincipal()
            :nvJogo(nullptr),carJogo(nullptr),sair(nullptr),leaderBoard(nullptr),nvJ(false)
            {}
            ~ControleMenuPrincipal();
        
    };
}