#pragma once
#include"commons.h"
using namespace std;
using namespace sf;
namespace Graficos{
    class Imagem{
        private:
            bool destruir;
            bool ativo;
        public:
            void Destruir(){ 
                destruir = true;
            }
            void setAtivo(const bool atv)
            {
                ativo = atv;
            }
            const bool getAtivo()
            {
                return ativo;
            }
            const bool getDestruir() const
            {
                return destruir;
            }
            virtual Drawable* Desenhar()=0;
            virtual Drawable* DesenharUI()=0;
            Imagem()
            :destruir(false),
            ativo(true)
            {}
            virtual ~Imagem()
            {}
    };
}