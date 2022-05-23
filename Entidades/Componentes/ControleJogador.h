#pragma once
#include"Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include"Posicao.h"
using namespace sf;
namespace Componentes
{
    class ControleJogador: public Componente
    {
        private:
            CorpoRigido* cR;
            Posicao* posicao;
            bool isGrounded;
            const Vector2f distanciaChao;
            void TestarChao();
            void Iniciar();
            
        public:
            void Atualizar();
            void AtualizarFixo();
            ControleJogador();

            ~ControleJogador()
            {}
    };
}