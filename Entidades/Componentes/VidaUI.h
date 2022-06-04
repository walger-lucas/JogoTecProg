#pragma once
#include "Vida.h"
#include "Jogador.h"
#include "ImgSprite.h"
#include "ImgTexto.h"
#include "Componente.h"
namespace Componentes
{
    class VidaUI: public Componente
    {
        private:
            Texture vida[2];
            Font guest3d;
            ImgSprite* jimmy,*janny;
            ImgTexto* pontos;
            Vector2f pos1,pos2,pos3,esc1,esc2;
            void Iniciar(){};
            void Render();
        public:
            VidaUI();
            ~VidaUI();
    };
}