#include"EventoBotao.h"
#include"commons.h"
#include"Colisor.h"
using namespace std;
using namespace sf;
namespace Gerenciadores{
    void EventoBotao::Apertar(sf::Vector2f pos)
    {
        if(getAtivo() && Colisoes::Colisor::Colide(col,pos))
        {
            BotaoApertado();
        }
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
    : col(pos,dim), ativo(true)
    {
        GerenciadorInputs::addBotao(this);
    }
    EventoBotao::EventoBotao(){}
    EventoBotao::~EventoBotao()
    {
        GerenciadorInputs::removeBotao(this);
    }
}