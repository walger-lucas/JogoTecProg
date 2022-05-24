#pragma once
#include "Entidade.h"
#include "GraficoSprite.h"
#include "GerenciadorArquivos.h"
#include "CorpoRigido.h"
using namespace Gerenciadores;

namespace Entidades
{

    class Plataforma: public Entidade
    {
        private:
            Posicao* posicao;
            CorpoRigido* corpoRigido;
            GraficoSprite* graficoSprite;
            Vector2f offset;
            void Carregar();
        public:
            Plataforma(Vector2f pos=Vector2f(0,0), const string& textura="cubo",Vector2f offset = Vector2f(0,0),Vector2f esc=Vector2f(1,1));
            ~Plataforma();
            void setOffsetTextura(Vector2f offset);
    };
}