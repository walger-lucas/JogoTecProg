#pragma once
#include "Obstaculo.h"
using namespace Gerenciadores;

namespace Entidades
{

    class Plataforma: public Obstaculo
    {
        private:
            Vector2f offset;
            void Carregar();
        public:
        	//tag significativa de chao
	        const static string TAG_GROUND;
            Plataforma(Vector2f posicao=Vector2f(0,0), const string& text="Plataforma.png",Vector2f offset = Vector2f(0,0),Vector2f esc=Vector2f(1,1));
            ~Plataforma();
            void setOffsetTextura(Vector2f offset);
    };
}