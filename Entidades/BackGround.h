#include "Entidade.h"
#include "GraficoSprite.h"
namespace Entidades
{
    class Background:public Entidade
    {
        private:
            Posicao* pos;
            GraficoSprite* gS;
            Texture texturaBackGround;
            void Carregar()
            {}
        public:
            Background(Vector2f inicio = Vector2f(0,0),float tamanhoX=50,const string& textura="background1.png")
            :pos(nullptr),gS(nullptr)
            {
                texturaBackGround.loadFromFile("Arquivos/Imagens/"+textura);
                pos = new Posicao(inicio.x,inicio.y);
                pos->setEscala(Vector2f(tamanhoX,tamanhoX));
                gS=new GraficoSprite(&texturaBackGround,0,false);
                addComponente(pos);
                addComponente(gS);

            }
            ~Background()
            {}
            
    };
}