#pragma once
#include "Componente.h"
#include "CorpoRigido.h"
#include "Posicao.h"
#include "IEscutaColisao.h"
using namespace sf;
namespace Componentes
{
    class ControleObstaculo: public Componente, public IEscutaColisao
    {
        protected:
            Posicao* pos;
            CorpoRigido* cR;
            bool objEmCima(ObjetoFisico* obj);
            virtual void Iniciar();
            virtual void AtualizarFixo(){};
            virtual void Atualizar(){};
            virtual void Colidiu(ObjetoFisico* obj)=0;
        public:
            static const string TAG_OBSTACULO;
            ControleObstaculo();
            virtual ~ControleObstaculo();
    };
}