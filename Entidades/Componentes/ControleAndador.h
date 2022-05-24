#pragma once
#include"Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include"Posicao.h"
#include"Vida.h"
#include"IEscutaColisao.h"
using namespace sf;
namespace Componentes
{
    class ControleAndador: public Componente, public IEscutaColisao
    {
        private:
            Posicao* pos;
            CorpoRigido* cR;
            Vida* vida;
            float velocidade;
            //const static Vector2f posBuscaChao;
            bool esquerdaChao,direitaChao,indoDireita;
            void TestarChao();
            void Iniciar();
            void AtualizarFixo();
            void Colidiu(ObjetoFisico* obj);
        public:
            ControleAndador();
            virtual ~ControleAndador();
            
    };
    
}