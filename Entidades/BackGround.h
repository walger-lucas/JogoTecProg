#include "Entidade.h"
#include "GraficoSprite.h"
namespace Entidades
{
    class Background:public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            Texture textura;
            void Carregar()
            {}
        public:
            Background(Vector2f inicio = Vector2f(0,0),float tamanhoX=50,const string& text="background1.png")
            :pos(nullptr),gS(nullptr)
            {
                textura.loadFromFile("Arquivos/Imagens/"+text);
                pos = new Posicao(inicio.x,inicio.y);
                pos->setEscala(Vector2f(tamanhoX,tamanhoX));
                gS = new GraficoSprite(&textura,0,false);
                addComponente(pos);
                addComponente(gS);

            }
            ~Background()
            {}
            
    };
}