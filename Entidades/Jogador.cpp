#include "Jogador.h"
#include "Cena.h"
namespace Entidades
{
    Jogador* Jogador::Jimmy = nullptr;
    Jogador* Jogador::Janny = nullptr;
    int Jogador::pontuacao(0);
    bool Jogador::doisJogadores(false);
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
    void Jogador::darPontos(int pontos)
    {
        pontuacao+=pontos;
    }
    void Jogador::zerarPontos()
    {
        pontuacao=0;
    }
    int Jogador::getPontos()
    {
        return pontuacao;
    }
    bool Jogador::SaoDoisJogadores()
    {
        return doisJogadores;
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
    void Jogador::setDoisJogadores(bool doisJog)
    {
        doisJogadores=doisJog;
    }
    bool Jogador::JogadoresVivos()
    {
        if(Janny||Jimmy)
            return true;
        return false;
    }
    int Jogador::vidasJogador(int i)
    {
        if(i==0)
        {
            if(Jimmy)
            {
                return Jimmy->vida->getVida();
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if(Janny)
            {
                return Janny->vida->getVida();
            }
            else
            {
                return 0;
            }  
        }
        

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
    void Jogador::escreverDados(ofstream& stream)
    {
        //Aviso se eh jimmy ou janny (0 Jimmy e Janny,1 Jimmy, 2 Janny,-1 nenhum)
        //depois vidas, cooldown de vida, posx posy, velx, vely
        int i;
        if(Jimmy&&Janny)
        {
            i=0;
            stream.write((char*)&i,sizeof(int));
        }else if(Jimmy)
        {
            i=1;
            stream.write((char*)&i,sizeof(int));
        }else if(Janny)
        {
            i=2;
            stream.write((char*)&i,sizeof(int));
        }
        else
        {
            i=-1;
            stream.write((char*)&i,sizeof(int));
        }
        int vidas;
        float cooldown;
        Vector2f pos;
        Vector2f vel;
        if(Jimmy)
        {
            vidas= Jimmy->vida->getVida();
            cooldown = Jimmy->vida->getTempoAtualCooldown();
            pos= Jimmy->pos->getPos();
            vel =Jimmy->cR->getVelocidade();
            stream.write((char*)&vidas,sizeof(int));
            stream.write((char*)&cooldown,sizeof(float));
            stream.write((char*)&pos.x,sizeof(float));
            stream.write((char*)&pos.y,sizeof(float));
            stream.write((char*)&vel.x,sizeof(float));
            stream.write((char*)&vel.y,sizeof(float));
        }
        if(Janny)
        {
            vidas= Janny->vida->getVida();
            cooldown = Janny->vida->getTempoAtualCooldown();
            pos= Janny->pos->getPos();
            vel =Janny->cR->getVelocidade();
            stream.write((char*)&vidas,sizeof(int));
            stream.write((char*)&cooldown,sizeof(float));
            stream.write((char*)&pos.x,sizeof(float));
            stream.write((char*)&pos.y,sizeof(float));
            stream.write((char*)&vel.x,sizeof(float));
            stream.write((char*)&vel.y,sizeof(float));
        }
    }
    void Jogador::lerDados(ifstream& stream,Cena* cena)
    {
        int i;
        stream.read((char*)&i,sizeof(int));
        
        int vidas;
        float cooldown;
        Vector2f pos;
        Vector2f vel;
        if(i==0||i==1)
        {
            stream.read((char*)&vidas,sizeof(int));
            
            stream.read((char*)&cooldown,sizeof(float));
            
            stream.read((char*)&pos.x,sizeof(float));
            
            stream.read((char*)&pos.y,sizeof(float));
            stream.read((char*)&vel.x,sizeof(float));
            stream.read((char*)&vel.y,sizeof(float));
            Jogador* j=new Jogador(pos,true);
            *cena+=j;
            j->vida->setVida(vidas);
            j->vida->setTempoAtualCooldown(cooldown);
            j->cR->setVelocidade(vel);
        }
        if(i==0||i==2)
        {
            stream.read((char*)&vidas,sizeof(int));
            stream.read((char*)&cooldown,sizeof(float));
            stream.read((char*)&pos.x,sizeof(float));
            stream.read((char*)&pos.y,sizeof(float));
            stream.read((char*)&vel.x,sizeof(float));
            stream.read((char*)&vel.y,sizeof(float));
            Jogador* j=new Jogador(pos,false);
            *cena+=j;
            j->vida->setVida(vidas);
            j->vida->setTempoAtualCooldown(cooldown);
            j->cR->setVelocidade(vel);
        }
    }
}