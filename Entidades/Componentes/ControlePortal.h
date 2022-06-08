#pragma once
#include "ControleObstaculo.h"
#include "Jogador.h"

using namespace sf;
namespace Componentes
{
    class ControlePortal: public ControleObstaculo
    {
        private:
            bool aberto;
            function<void(void)> entrar;
            Texture texturaAberto,texturaFechado;
            GraficoSprite* gS;
            void Colidiu(ObjetoFisico* obj)
            {
                CorpoRigido* cp = obj->getCorpoRigido();
                if(aberto&&cp)
                {
                    if(cp->getEntidade()->temTag(Jogador::TAG_JOGADOR)&& entrar&&Jogador::JogadoresProximos())
                    {
                        entrar();
                    }
                }
            }
            void Render()
            {
                if(aberto)
                {
                    Vector2f dist = Jogador::localizacaoJogadorProximo(gS->getSprite()->getCentro())-gS->getSprite()->getCentro();
                    float distancia = std::sqrt(dist.x*dist.x+dist.y*dist.y);
                    if(distancia<3.5)
                    {
                        gS->getSprite()->setTextura(texturaAberto);
                    }
                    else
                    {
                        gS->getSprite()->setTextura(texturaFechado);
                    }
                }
                else
                {
                    gS->getSprite()->setTextura(texturaFechado);
                }
            }
            void Iniciar()
            {
                gS = getEntidade()->getComponente<GraficoSprite>();
                pos= getEntidade()->getComponente<Posicao>();
                getEntidade()->getComponente<CorpoRigido>()->addEscuta(this);
            }
        public:
            void setAberto(bool abt)
            {
                aberto = abt;
            }
            ControlePortal(bool aberto = false,function<void(void)> entrada=nullptr)
            :aberto(aberto),entrar(entrada),gS(nullptr)
            {
                texturaAberto.loadFromFile("Arquivos/Imagens/PortalAberto.png");
                texturaFechado.loadFromFile("Arquivos/Imagens/PortalFechado.png");
            }
            ~ControlePortal(){}
            
    };
    
}