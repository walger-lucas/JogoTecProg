#pragma once
#include "Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include "ControleObstaculo.h"
#include "Posicao.h"
#include "Vida.h"
#include "IEscutaColisao.h"

using namespace sf;
namespace Componentes
{
    class ControleEspinho: public ControleObstaculo
    {
        private:
            void Colidiu(ObjetoFisico* obj);
            void AtualizarFixo();
        public:
            ControleEspinho();
            virtual ~ControleEspinho();
            
    };
    
}