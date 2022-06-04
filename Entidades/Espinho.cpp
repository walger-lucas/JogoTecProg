#include "Espinho.h"
#include "Cena.h"
#include "commons.h"
namespace Entidades
{
    list<Espinho*> Espinho::espinhos= list<Espinho*>();
    void Espinho::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
    }
    void Espinho::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos;
        Vector2f vel;
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        Espinho* esp = new Espinho(pos);
        *cena+=esp;
        esp->cR->setVelocidade(vel);

    }
    void Espinho::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));
    }
    Espinho::Espinho(Vector2f posicao)
    :Entidade("Espinho"),
    pos(new Posicao(posicao.x,posicao.y)),
    gS(nullptr),
    cR(new CorpoRigido(true,true,true)),
    cE(new ControleEspinho()),
    vd(new Vida(1))
    {
        pos->setEscala(Vector2f(0.5,0.5));
        texturaespinho.loadFromFile("Arquivos/Imagens/Espinho.png");
        gS = new GraficoSprite(&texturaespinho,1,false);
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cE));
        this->addComponente(static_cast<Componente*> (vd));
        espinhos.push_front(this);
    }
    Espinho::~Espinho()
    {
        espinhos.remove(this);
    }

    void Espinho::escreverDados(ofstream& stream)
    {
        int tam = espinhos.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto espinho : espinhos)
        {
            espinho->escreverDadosPessoal(stream);
        }
    }
    void Espinho::lerDados(ifstream& stream, Cena* cena)
    {
        int tam;
        try
        {
            stream.read((char*)&tam,sizeof(int));
            for(int i =0;i<tam;i++)
            {
                lerDadosPessoal(stream,cena);
            }
        }
        catch(const std::ifstream::failure &e)
        {
            cerr<<"Impossivel abrir dados dos Espinhos"<<endl;
        }
        
        
    }
}