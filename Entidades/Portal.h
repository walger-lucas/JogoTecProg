#pragma once
#include "Obstaculo.h"
#include "ControlePortal.h"
namespace Entidades
{
    class Portal: public Obstaculo
    {
        private:
            ControlePortal* cP;
            void Carregar()
            {
                cR->setDim(Vector2f(2.5,2.5));
            }
        public:
            void AbrirPortar(bool port)
            {
                cP->setAberto(port);
            }
            Portal(const Vector2f& posicao = Vector2f(0,0),function<void(void)> funcao=nullptr,bool aberto = false)
            :Obstaculo("Portal"),
            cP(new ControlePortal(aberto,funcao))
            {
                pos = new Posicao(posicao.x,posicao.y);
                gS = nullptr;
                cR = new CorpoRigido(false,false,false);
                textura.loadFromFile("Arquivos/Imagens/PortalFechado.png");
                this->pos->setEscala(Vector2f(2.5,2.5));
                gS= new GraficoSprite(&textura,1,false);
                addComponente(this->pos);
                addComponente(gS);
                addComponente(cR);
                addComponente(cP);
            }
            ~Portal(){}
    };
}