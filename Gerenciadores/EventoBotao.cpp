#include"EventoBotao.h"
#include"commons.h"
#include"Colisor.h"
using namespace std;
using namespace sf;
namespace Gerenciadores{
    void EventoBotao::Apertar(sf::Vector2f pos)
    {

        if(getAtivo()&&Colisoes::Colisor::Colide(col,pos))
        {
            if(funcApertar!=nullptr && !clicadoNoUltimoTeste)
                funcApertar();
            clicadoNoUltimoTeste = true;
        }

    }
    void EventoBotao::setPonteiros(Vector2f* pos,Vector2f* dim)
    {
        col.setPPos(pos);
        col.setPDim(dim);
    }
    void EventoBotao::Desapertar()
    {
        if(getAtivo()&&clicadoNoUltimoTeste)
        {
            
            if(funcDesapertar!= nullptr)
            {
                funcDesapertar(); 
            }
            clicadoNoUltimoTeste=false;
        }
    }
    void EventoBotao::setFuncApertar(function<void()> func)
    {
        funcApertar = func;
    }
    void EventoBotao::setFuncDesapertar(function<void()> func)
    {
        funcDesapertar = func;
    }
    const bool EventoBotao::getAtivo() const
    {
        return ativo;
    }
    void EventoBotao::setAtivo(const bool atv)
    {
        ativo = atv;
    }
    EventoBotao::EventoBotao(Vector2f* pos, Vector2f* dim)
    : col(pos,dim), ativo(true),clicadoNoUltimoTeste(false), funcApertar(nullptr), funcDesapertar(nullptr)
    {
        GerenciadorInputs::addBotao(this);
    }
    EventoBotao::EventoBotao()
    :col(),ativo(false),clicadoNoUltimoTeste(false),funcApertar(nullptr), funcDesapertar(nullptr)
    {
        GerenciadorInputs::addBotao(this);
    }
    EventoBotao::~EventoBotao()
    {
        GerenciadorInputs::removeBotao(this);
    }
}