#include "BotaoEntidade.h"

using namespace sf;
using namespace std;
using namespace Componentes;
namespace Entidades
{
    BotaoEntidade::BotaoEntidade(Vector2f pos,float tam,const string& txt, Vector2f offset,const string& textura,const string& fonte,function<void()> apt,function<void()> dapt)
    :Entidade("Botao "+txt),bot(nullptr)
    {
        texturaBot.loadFromFile("Arquivos/Imagens/"+textura);
        addComponente(new Posicao(pos.x,pos.y));
        addComponente(new GraficoSprite(&texturaBot,2,true));
        
        bot = new Botao(&texturaBot,txt);
        addComponente(bot);
        bot->setFuncApertar(apt);
        bot->setFuncDesapertar(dapt);
        bot->setOffsetTexto(offset);
        bot->setTamanhoTexto(tam);
        fonteTexto.loadFromFile("Arquivos/Fontes/"+fonte);
        bot->setFonte(fonteTexto);
    }
    void BotaoEntidade::Carregar(){

    }
    void BotaoEntidade::setTexto(const string& txt)
    {
        if(bot)
            bot->setTexto(txt);
    }
    BotaoEntidade::~BotaoEntidade(){}
}