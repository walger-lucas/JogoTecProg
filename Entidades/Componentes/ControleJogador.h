#pragma once
#include"Componente.h"
#include "Movimento.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include"Posicao.h"
#include "IEscutaColisao.h"
using namespace sf;
namespace Componentes
{
    class ControleJogador: public Componente, public IEscutaColisao
    {
        private:
            CorpoRigido* cR;
            Posicao* posicao;
            Vida* vd;
            bool isGrounded;
            Movimento movimento;
            const Vector2f distanciaChao;
            void Colidiu(ObjetoFisico* obj);
            Keyboard::Key up,left,right,down;
            
            void TestarChao();
            void Iniciar();
            void Atualizar();
            void AtualizarFixo();   
        public:
            void setControles(Keyboard::Key up,Keyboard::Key down,Keyboard::Key left,Keyboard::Key right);
            ControleJogador();

            virtual ~ControleJogador()
            {}
    };
}