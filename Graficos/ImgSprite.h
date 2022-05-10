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
            const Vector2f* posicao;
            const Vector2f* escala;
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
            Drawable* Desenhar();
            Drawable* DesenharUI();
            void setTextura(const Texture& textura);
            void setOrigin(const Vector2f pos);
            ImgSprite(const Vector2f* pos=nullptr, const Vector2f* escala = nullptr)
            : Imagem(), posicao(pos),escala(escala)
            {}
            ~ImgSprite() 
            {}
            
    };
}