#pragma once
#include "commons.h"
#include "Componente.h"
#include "Tempo.h"
using namespace std;
namespace Componentes{
    class Vida: public Componente
    {
        private:
            int vida;
            float tempoImune,cont_tempoImune;

            function<void(int)> machucado;
            void Iniciar(){};
            void Atualizar()
            {
                if(cont_tempoImune<=10*tempoImune)
                    cont_tempoImune+= Configs::Tempo::getDeltaTempoControlado();
            }
        public:
            void Machucar(int dano){
                if(cont_tempoImune>=tempoImune)
                {
                    vida-=dano;
                    if(machucado)
                        machucado(dano);
                    cont_tempoImune=0;
                }
            }
            const bool Vivo() const
            {
                return vida>0;
            }
            const int getVida() const
            {
                return vida;
            }
            void setTempoAtualCooldown(float tempo)
            {
                cont_tempoImune= tempo;
            }
            float getTempoAtualCooldown()
            {
                return cont_tempoImune;
            }
            void setVida(int vida)
            {
                this->vida = vida;
            }
            void setMachucadoFunc(function<void(int)> machucar)
            {
                machucado = machucar;
            }
            Vida(int vidainit=1,float tempoImune=0,function<void(int)> machucar=nullptr)
            : Componente(),vida(vidainit),tempoImune(tempoImune),cont_tempoImune(tempoImune),machucado(machucar)
            {}
            ~Vida(){};
            

    };

}