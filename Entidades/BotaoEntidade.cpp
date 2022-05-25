#include "BotaoEntidade.h"

using namespace sf;
using namespace std;
using namespace Componentes;
namespace Entidades
{
    BotaoEntidade::BotaoEntidade(Vector2f pos,float tam,const string& txt, Vector2f offset,const string& textura,const string& fonte,function<void()> apt,function<void()> dapt)
    :Entidade("Botao "+txt)
    {
        texturaBot.loadFromFile("Arquivos/Imagens/"+textura);
        addComponente(new Posicao(pos.x,pos.y));
        addComponente(new GraficoSprite(&texturaBot,2,true));
        
        Botao* b = new Botao(&texturaBot,txt);
        addComponente(b);
        b->setFuncApertar(apt);
        b->setFuncDesapertar(dapt);
        b->setOffsetTexto(offset);
        b->setTamanhoTexto(tam);
        fonteTexto.loadFromFile("Arquivos/Fontes/"+fonte);
        b->setFonte(fonteTexto);
    }
    void BotaoEntidade::Carregar(){

    }
    BotaoEntidade::~BotaoEntidade(){}
}