#include "Plataforma.h"
using namespace Gerenciadores;
using namespace Componentes;
namespace Entidades
{
    	//tag significativa de chao
	const string Plataforma::TAG_GROUND= "ground";
    void Plataforma::Carregar()
    {

        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));
        gS->getSprite()->setOrigin(offset);
    }
    Plataforma::Plataforma(Vector2f posicao, const string& text,Vector2f offset,Vector2f esc)
    : Obstaculo("Plataforma"),
    offset(offset)
    {
        pos = new Posicao(posicao.x,posicao.y);
        cR = new CorpoRigido(true,false,true);
        gS = nullptr;
        textura.loadFromFile("Arquivos/Imagens/"+text);
        gS =new GraficoSprite(&textura,1,false);
        pos->setEscala(esc);
        addComponente(pos);
        addComponente(cR);
        addComponente(gS);
        addTag(TAG_GROUND);
    }

    Plataforma::~Plataforma()
    {}
    void Plataforma::setOffsetTextura(Vector2f offset)
    {
        gS->getSprite()->setOrigin(offset);
    }
}