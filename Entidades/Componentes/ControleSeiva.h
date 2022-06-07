#pragma once
#include "ControleObstaculo.h"

using namespace sf;
namespace Componentes
{
    class ControleSeiva: public ControleObstaculo
    {
        private:
            void Colidiu(ObjetoFisico* obj);
            void AtualizarFixo();
        public:
            ControleSeiva();
            virtual ~ControleSeiva();
            
    };
    
}