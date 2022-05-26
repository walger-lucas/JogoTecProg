#pragma once
#include"Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include "ControleInimigo.h"
#include"Posicao.h"
#include"Vida.h"
#include"IEscutaColisao.h"
using namespace sf;
namespace Componentes
{
    class ControleAndador: public ControleInimigo
    {
        private:
            float velocidade;
            void AtualizarFixo();
            void Colidiu(ObjetoFisico* obj);
        public:
            ControleAndador();
            virtual ~ControleAndador();
            
    };
    
}