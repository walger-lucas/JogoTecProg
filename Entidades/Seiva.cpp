#include "Seiva.h"
#include "Cena.h"
namespace Entidades
{
    list<Seiva*> Seiva::seivas= list<Seiva*>();
    void Seiva::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
    }
    void Seiva::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados escritos em ordem: pos,Velocidade
        Vector2f pos;
        Vector2f vel;
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        Seiva* seiva = new Seiva(pos);
        *cena+=seiva;
        seiva->cR->setVelocidade(vel);

    }
    void Seiva::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

    }
    Seiva::Seiva(Vector2f posicao):
    Entidade("Seiva"),
    pos(new Posicao(posicao.x,posicao.y)),
    gS(nullptr),
    cR(new CorpoRigido(false,true,true)),
    cS(new ControleSeiva()),
    vd(new Vida(1))
    {
        texturaSeiva.loadFromFile("Arquivos/Imagens/seiva.png");
        gS = new GraficoSprite(&texturaSeiva,2,false);
        pos->setEscala(Vector2f(0.8,0.8));
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cS));
        this->addComponente(static_cast<Componente*> (vd));
        seivas.push_front(this);
    }
    void Seiva::escreverDados(ofstream& stream)
    {
        int tam = seivas.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto seiva : seivas)
        {
            seiva->escreverDadosPessoal(stream);
        }
    }
    Seiva::~Seiva()
    {
        seivas.remove(this);
    }
    void Seiva::lerDados(ifstream& stream, Cena* cena)
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
            cerr<<"Impossivel abrir dados das Seivas"<<endl;
        }
    }
}