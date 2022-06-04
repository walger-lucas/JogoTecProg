#pragma once
#include"Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include"Posicao.h"
#include"Vida.h"
#include"IEscutaColisao.h"
#include "ControleInimigo.h"
using namespace sf;
namespace Componentes
{
    class ControleAndador: public ControleInimigo
    {
        private:
            void AtualizarFixo();
            void Colidiu(ObjetoFisico* obj);
        public:
            ControleAndador();
            virtual ~ControleAndador();
        
            
    };
    
}