#pragma once
#include "commons.h"
#include "Componente.h"
namespace Componentes{
    class Vida: public Componente
    {
        private:
            int vida;
            void Iniciar(){};
        public:
            void Machucar(int dano){
                vida-=dano;
            }
            const bool Vivo() const
            {
                return vida>0;
            }
            const int getVida() const
            {
                return vida;
            }
            Vida(int vidainit=1)
            : Componente(),vida(vidainit)
            {}
            ~Vida(){};
            

    };

}