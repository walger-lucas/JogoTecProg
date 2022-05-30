#pragma once
#include "Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include "Obstaculo.h"
#include "Posicao.h"
#include "Vida.h"
#include "IEscutaColisao.h"

using namespace sf;
namespace Componentes
{
    class ControleSeiva: public Obstaculo
    {
        private:
            void Colidiu(ObjetoFisico* obj);
        public:
            ControleSeiva();
            virtual ~ControleSeiva();
            
    };
    
}