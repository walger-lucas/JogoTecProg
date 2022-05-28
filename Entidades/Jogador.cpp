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
    Vector2f Jogador::localizacaoJogadorProximo(const Vector2f posAtual)
    {
        Vector2f dist1;
        Vector2f dist2;
        if(Jimmy&&Janny)
        {
            dist1 = posAtual- Jimmy->cR->getCentro();
            dist2 = posAtual - Janny->cR->getCentro();
            if(dist1.x*dist1.x+dist1.y*dist1.y>dist2.x*dist2.x+dist2.y*dist2.y)
            {
                return Janny->cR->getCentro();
            }
            else
            {
                return Jimmy->cR->getCentro();
            }
        }
        else if(Jimmy)
            return Jimmy->cR->getCentro();
        else if(Janny)
            return Janny->cR->getCentro();
        else
            return Vector2f(10000,10000);
            
    }
    Vector2f Jogador::localizacaoMediaJogadores()
    {
        Vector2f pos1(0,0), pos2(0,0);
        if(Jimmy&&Janny)
        {
            return (Jimmy->cR->getCentro()+Janny->cR->getCentro())*0.5F;
        }
        else if(Jimmy)
        {
            return Jimmy->cR->getCentro();
        }
        else if(Janny)
        {
            return Janny->cR->getCentro();
        }
        return Vector2f(0,0);
    }
    bool Jogador::JogadoresVivos()
    {
        if(Janny||Jimmy)
            return true;
        return false;
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