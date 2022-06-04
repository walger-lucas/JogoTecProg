#pragma once
#include "Entidade.h"
#include "CorpoRigido.h"
#include "GraficoSprite.h"
#include "ControlePortal.h"
namespace Entidades
{
    class Portal: public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            CorpoRigido* cR;
            ControlePortal* cP;
            Texture texturaInicial;
            void Carregar()
            {
                cR->setDim(Vector2f(2.5,2.5));
            }
        public:
            void AbrirPortar(bool port)
            {
                cP->setAberto(port);
            }
            Portal(const Vector2f& pos = Vector2f(0,0),function<void(void)> funcao=nullptr,bool aberto = false)
            :pos(new Posicao(pos.x,pos.y)),gS(nullptr),cR(new CorpoRigido(false,false,false)),cP(new ControlePortal(aberto,funcao))
            {
                texturaInicial.loadFromFile("Arquivos/Imagens/PortalFechado.png");
                this->pos->setEscala(Vector2f(2.5,2.5));
                gS= new GraficoSprite(&texturaInicial,1,false);
                addComponente(this->pos);
                addComponente(gS);
                addComponente(cR);
                addComponente(cP);
            }
            ~Portal(){}
    };
}