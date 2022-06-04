#pragma once
#include "ControleInimigo.h"
namespace Componentes
{
    class ControleChefaoPulador: public ControleInimigo
    {
        private:
            //ponteiro para o chefao que fica em cima da pilha, e de baixo da pilha
            ControleChefaoPulador *cima,*baixo;
            float tempoPularCount,tempoPular;
            Texture coelhoDireita,coelhoEsquerda;
            void AtualizarFixo();
            void Atualizar();
            void Render();
            void Colidiu(ObjetoFisico* obj);
            void Soltar();
        public:
            void setCima(ControleChefaoPulador* cima);
            void setBaixo(ControleChefaoPulador* cima);
            const float getTempoRec() const;
            const float getTempoCont() const;
            void setTempoRec(float tempo);
            void setTempoCont(float tempo);
            ControleChefaoPulador* getCima();
            ControleChefaoPulador* getBaixo();
            void Pular();
            ControleChefaoPulador();
            ~ControleChefaoPulador();



    };
}