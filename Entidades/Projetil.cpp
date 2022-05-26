#include "Projetil.h"
#include "Jogador.h"
namespace Entidades{
    const string Projetil::TAG_PROJETIL = "projetil";
    Projetil::Projetil(Vector2f pos,Vector2f velInit, int dano,float tam)
    :Entidade(),
    pos(new Posicao(pos.x,pos.y)),
    gS(nullptr),
    cR(new CorpoRigido(true,true,true)),
    velInit(velInit),
    tam(tam),
    dano(dano)
    {
        texturaProjetil.loadFromFile("Arquivos/Imagens/Projetil.png");
        gS = new GraficoSprite(&texturaProjetil,2,false);
        addComponente(this->pos);
        addComponente(gS);
        addComponente(cR);
        this->pos->setEscala(Vector2f(tam,tam));
        addTag(TAG_PROJETIL);

    }
    Projetil::~Projetil()
    {}
    void Projetil::Carregar()
    {
        cR->setVelocidade(velInit);
        cR->addEscuta(this);
        cR->setDim(Vector2f(tam,tam));
        
    }
    void Projetil::Colidiu(ObjetoFisico* obj)
    {
        if((obj&&obj->getColidivel()))
        {
            CorpoRigido* cp = obj->getCorpoRigido();
            if(cp &&cp->getEntidade()->temTag(TAG_JOGADOR))
                cp->getEntidade()->getComponente<Vida>()->Machucar(dano);
            Destruir();
        }
    }
}