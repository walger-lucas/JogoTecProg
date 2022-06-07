#include "Trampolim.h"
#include "Cena.h"
namespace Entidades
{
    list<Trampolim*> Trampolim::trampolins= list<Trampolim*>();
    void Trampolim::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
    }
    void Trampolim::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos;
        Vector2f vel;
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        Trampolim* tramp = new Trampolim(pos);
        *cena+=tramp;
        tramp->cR->setVelocidade(vel);

    }
    Trampolim::Trampolim(Vector2f posicao)
    :Obstaculo("Trampolim"),
    cT(new ControleTrampolim())
    {
        pos = new Posicao(posicao.x,posicao.y);
        gS = nullptr;
        cR = new CorpoRigido(true,true,true);
        textura.loadFromFile("Arquivos/Imagens/trampolim.png");
        pos->setEscala(Vector2f(0.5,0.5));
        gS = new GraficoSprite(&textura,1,false);
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cT));
        trampolins.push_front(this);
    }
    Trampolim::~Trampolim()
    {
        trampolins.remove(this);
    }
    void Trampolim::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));
    }

    void Trampolim::escreverDados(ofstream& stream)
    {
        int tam = trampolins.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto trampolim : trampolins)
        {
            trampolim->escreverDadosPessoal(stream);
        }
    }
    void Trampolim::lerDados(ifstream& stream, Cena* cena)
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
            cerr<<"Impossivel abrir dados dos Trampolins"<<endl;
        }
        
        
    }
}