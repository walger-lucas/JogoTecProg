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
            void machucar(int dano){
                vida-=dano;
            }
            const bool vivo() const
            {
                return vida>0;
            }
            const int getVida() const
            {
                return vida;
            }
            Vida(int vidainit)
            : Componente(),vida(vidainit)
            {}
            ~Vida(){};
            

    };

}