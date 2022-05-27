#include "Jogador.h"
namespace Entidades
{
    Jogador* Jogador::Jimmy = nullptr;
    Jogador* Jogador::Janny = nullptr;
    const string Jogador::TAG_JOGADOR="jogador";

    void Jogador::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

    }

    Jogador::Jogador(Vector2f posicao,bool jimmy)
    : Entidade("Jogador"),
    pos(new Posicao(posicao.x,posicao.y)),
    gS(nullptr),
    cR(new CorpoRigido(true,true,true)),
    cJ(new ControleJogador()),
    vida(new Vida(4,2,std::bind(&Jogador::Dano,this,std::placeholders::_1))),
    jimmy(jimmy)
    {
        if(jimmy)
        {
            textura.loadFromFile("Arquivos/Imagens/Jimmy.png");
            Jimmy=this;
            cJ->setControles(Keyboard::Key::Up,Keyboard::Key::Down,Keyboard::Key::Left,Keyboard::Key::Right);
        }
        else
        {
            Janny=this;
            textura.loadFromFile("Arquivos/Imagens/Janny.png");
            cJ->setControles(Keyboard::Key::W,Keyboard::Key::S,Keyboard::Key::A,Keyboard::Key::D);
        }
        gS=new GraficoSprite(&textura,1,false);
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (vida));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cJ));
        addTag(TAG_JOGADOR);
    }
    Jogador::~Jogador()
    {
        if(jimmy)
            Jimmy=nullptr;
        else
            Janny=nullptr;

    }
}