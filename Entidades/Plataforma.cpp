#include "Plataforma.h"
using namespace Gerenciadores;
using namespace Componentes;
namespace Entidades
{
    void Plataforma::Carregar()
    {

        Vector2f dim = graficoSprite->getSprite()->getDim();
        Vector2f esc =graficoSprite->getSprite()->getEscala();
        corpoRigido->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));
        graficoSprite->getSprite()->setOrigin(offset);
    }
    Plataforma::Plataforma(Vector2f pos, const string& textura,Vector2f offset,Vector2f esc)
    : Entidade("Plataforma"),
    posicao(new Posicao(pos.x,pos.y)),
    corpoRigido(new CorpoRigido(true,false,false)),
    graficoSprite(new GraficoSprite(GerenciadorArquivos::getTextura(textura),1,false)),
    offset(offset)
    {
        posicao->setEscala(esc);
        addComponente(posicao);
        addComponente(corpoRigido);
        addComponente(graficoSprite);
        addTag(TAG_GROUND);
    }

    Plataforma::~Plataforma()
    {}
    void Plataforma::setOffsetTextura(Vector2f offset)
    {
        graficoSprite->getSprite()->setOrigin(offset);
    }
}