#pragma once
#include "Grafico.h"
#include"ImgSprite.h"
#include"Imagem.h"
using namespace std;
using namespace sf;
using namespace Graficos;
namespace Componentes
{
    class GraficoSprite: public Grafico
    {
        private:
            ImgSprite* sprite;
            Texture* texture;
            Imagem* Construir();
            virtual void Render() {}
        public:
            GraficoSprite(Texture* txt=nullptr,int layer = 0, bool ui=false);
            ImgSprite* getSprite();
            virtual ~GraficoSprite();
    };
}