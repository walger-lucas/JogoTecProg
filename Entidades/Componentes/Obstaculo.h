#pragma once
#include "Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include "Posicao.h"
#include "Vida.h"
#include "IEscutaColisao.h"
#include "GraficoSprite.h"
using namespace sf;
namespace Componentes
{
    class Obstaculo: public Componente, public IEscutaColisao
    {
        protected:
            Posicao* pos;
            CorpoRigido* cR;
            Vida* vida;
            GraficoSprite* gS;
            bool objEmCima(ObjetoFisico* obj);
            virtual void Iniciar();
            virtual void AtualizarFixo(){};
            virtual void Atualizar(){};
            virtual void Colidiu(ObjetoFisico* obj)=0;
        public:
            static const string TAG_OBSTACULO;
            Obstaculo();
            virtual ~Obstaculo();
    };
}