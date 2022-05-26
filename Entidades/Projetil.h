#pragma once
#include "CorpoRigido.h"
#include "GraficoSprite.h"
#include "Posicao.h"
#include "IEscutaColisao.h"
using namespace Gerenciadores;
using namespace Colisoes;
using namespace Graficos;
namespace Entidades
{
    
    class Projetil: public Entidade, public IEscutaColisao
    {
        private:
            
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            Texture texturaProjetil;
            Vector2f velInit;
            float tam;
            const int dano;
            void Colidiu(ObjetoFisico* obj);
            void Carregar();
        public:
            static const string TAG_PROJETIL;
            Projetil(Vector2f pos=Vector2f(0,0),Vector2f velInit= Vector2f(0,0), int dano= 1,float tam = 0.3);
            virtual ~Projetil();
    };
}