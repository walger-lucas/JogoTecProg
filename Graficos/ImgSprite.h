#pragma once
#include"Imagem.h"
#include"Colisor.h"
using namespace std;
using namespace sf;
using namespace Colisoes;
namespace Graficos
{
    class ImgSprite: public Imagem{
        private:
            Vector2f* posicao;
            Vector2f* escala;
            Vector2f dimensao;
            
            Sprite sprite;
        public:
            const Vector2f getPos() const;
            const Vector2f getDim() const;
            const Vector2f getEscala() const;
            //set dimensao apropriada
            void setDim(Vector2f dim);
            //set dim com x igual a uma unidade e y equivalente ao tamanho da textura ou o contrario
            void setDim(bool x=false);
            const Vector2f getCentro() const;
            virtual Drawable* Desenhar();
            virtual Drawable* DesenharUI();
            void setTextura(const Texture& textura);
            ImgSprite(Vector2f* pos=nullptr, Vector2f* escala = nullptr)
            : Imagem(), posicao(pos),escala(escala)
            {}
            ~ImgSprite() 
            {}
            
    };
}