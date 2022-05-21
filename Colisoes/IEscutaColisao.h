#pragma once
#include"ObjetoFisico.h"
namespace Colisoes{
    class IEscutaColisao{
        friend CorpoRigido;
        protected:
            virtual void Colidiu(ObjetoFisico* obj)=0;
        public:
            IEscutaColisao()
            {}
            ~IEscutaColisao()
            {}
    };
}