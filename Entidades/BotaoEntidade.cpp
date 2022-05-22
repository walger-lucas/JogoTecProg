#include "BotaoEntidade.h"
#include "GerenciadorArquivos.h"
using namespace sf;
using namespace std;
using namespace Componentes;
namespace Entidades
{
    BotaoEntidade::BotaoEntidade(Vector2f pos,float tam,const string& txt, Vector2f offset,const string& textura,const string& fonte,function<void()> apt,function<void()> dapt)
    :Entidade("Botao "+txt)
    {
        addComponente(new Posicao(pos.x,pos.y));
        addComponente(new GraficoSprite(GerenciadorArquivos::getTextura("cubo"),2,true));
        Botao* b = new Botao(GerenciadorArquivos::getTextura(textura),txt);
        addComponente(b);
        b->setFuncApertar(apt);
        b->setFuncDesapertar(dapt);
        b->setOffsetTexto(offset);
        b->setTamanhoTexto(tam);
        b->setFonte(*GerenciadorArquivos::getFonte(fonte));
    }
    void BotaoEntidade::Carregar(){

    }
    BotaoEntidade::~BotaoEntidade(){}
}