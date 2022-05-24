#include"GraficoSprite.h"
#include"commons.h"
#include"Entidade.h"
using namespace std;
using namespace sf;
using namespace Graficos;
namespace Componentes{
    Imagem* GraficoSprite::Construir()
    {
        //ve se entidade existe
        if(getEntidade()==nullptr)
        {
            cout << "Componente sem entidade\n";
            return nullptr;
        }
        //tenta encontrar posicao
        Posicao* p = getEntidade()->getComponente<Posicao>();
        if(p==nullptr)
        {
            cout<<"Entidade: "<< getEntidade()->getNome()<<" sem componente posicao. \n Impossivel adicionar componente GraficoSprite\n";
            return nullptr;
        }
        //cria textura com base na posicao
        sprite = new ImgSprite(p->getPPos(),p->getPEsc());
        sprite->setTextura(*texture);
        return sprite;
    }
    ImgSprite* GraficoSprite::getSprite()
    {
        return sprite;
    }

    GraficoSprite::GraficoSprite(Texture* txt,int layer, bool ui)
    :Grafico(layer,ui),sprite(nullptr),texture(txt)
    {}
    GraficoSprite::~GraficoSprite()
    {
        if(sprite)
            sprite->Destruir();
    }
}