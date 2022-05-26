#pragma once
#include"Componente.h"
#include "Vida.h"
#include "CorpoRigido.h"
#include"Posicao.h"
#include"Vida.h"
#include"IEscutaColisao.h"
#include "GraficoSprite.h"
using namespace sf;
namespace Componentes
{
    class ControleInimigo: public Componente, public IEscutaColisao
    {
        protected:
            Posicao* pos;
            CorpoRigido* cR;
            Vida* vida;
            GraficoSprite* gS;
            const Vector2f posBuscaChao;
            bool esquerdaChao,direitaChao,indoDireita;
            void TestarChao();
            bool objEmCima(ObjetoFisico* obj);
            bool objEmBaixo(ObjetoFisico* obj);
            virtual void Iniciar();
            virtual void AtualizarFixo(){};
            virtual void Atualizar(){};
            virtual void Colidiu(ObjetoFisico* obj)=0;
        public:
            ControleInimigo(Vector2f posChao=Vector2f(0,-0.51));
            virtual ~ControleInimigo();
    };
}