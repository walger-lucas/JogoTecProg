#pragma once
#include"./commons.h"
#include"Componente.h"
using namespace sf;
namespace Componentes{
    class Posicao: public Componente
    {
        private:
            Vector2f posicao;
            Vector2f escala;
            void Iniciar(){};
        public:
            const float getX() const;
            const float getY() const;
            const float getEscX() const;
            const float getEscY() const;
            const Vector2f getPos() const;
            const Vector2f getEscala() const;
            const Vector2f* getPPos() const;
            const Vector2f* getPEsc() const;
            void setPos(Vector2f pos);
            void setEscala(Vector2f esc);
            Posicao(float x =0,float y = 0)
            :Componente(), posicao(x,y), escala(1,1)
            {}
            ~Posicao()
            {}
    };
}