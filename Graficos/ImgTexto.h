#pragma once
#include"Imagem.h"
#include"commons.h"
using namespace sf;
using namespace std;
namespace Graficos{
    class ImgTexto: public Imagem
    {
        private:
            Text texto;
            const Vector2f* posicao;
            float tamanho;
        public:
            const Vector2f getPos() const;
            void setTexto(const string& texto);
            void setTam(const float tam);
            const float getTam() const;
            void setPPos(Vector2f* pos);
            void setFont(const Font& fonte);
            void setPixChar(const int pix);
            void setCor(const Color& cor);
            void setOrigin(const Vector2f pos);
            Drawable* Desenhar();
            Drawable* DesenharUI();
            ImgTexto(const Vector2f* pos = nullptr,const float tam= 1);
            ~ImgTexto();
    };


}