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
            Movimento movimento;
            bool isGrounded;
            const Vector2f distanciaChao;
            void Colidiu(ObjetoFisico* obj);
            Keyboard::Key up,left,right,down;
            
            void TestarChao();
            void Iniciar();
            void Atualizar();
            void AtualizarFixo();   
        public:
            void setControles(Keyboard::Key up,Keyboard::Key down,Keyboard::Key left,Keyboard::Key right);
            void setModVelocidade(const float mod);
            void setModPulo(const float mod);
            ControleJogador();

            virtual ~ControleJogador()
            {}
    };
}