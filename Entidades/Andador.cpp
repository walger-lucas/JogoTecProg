#include "Andador.h"
#include "Cena.h"

namespace Entidades{

    list<Andador*> Andador::andadores= list<Andador*>();
    void Andador::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem: Vida,Posicao,Velocidade,direcao
        int vidas = this->vd->getVida();
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        bool dir = this->cA->getIndoDireita();
        stream.write((char*)&vidas,sizeof(int));
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
        stream.write((char*)&dir,sizeof(bool));
    }
    void Andador::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados lidos em ordem: Vida,Posicao,Velocidade,direcao
        int vidas;
        Vector2f pos;
        Vector2f vel;
        bool dir;
        stream.read((char*)&vidas,sizeof(int));
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        stream.read((char*)&dir,sizeof(bool));
        Andador* anda = new Andador(pos);
        *cena+=anda;
        anda->vd->setVida(vidas);
        anda->cR->setVelocidade(vel);
        anda->cA->setIndoDireita(dir);

    }
    void Andador::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

    }
    Andador::Andador(Vector2f posicao)
    : Personagem("Andador"),
    cA(new ControleAndador())
    {
        pos = new Posicao(posicao.x,posicao.y);
        gS = nullptr;
        cR = new CorpoRigido(true,true,true);
        vd = new Vida(1);
        textura.loadFromFile("Arquivos/Imagens/Andador.png");
        gS =new GraficoSprite(&textura,1,false);
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cA));
        this->addComponente(static_cast<Componente*> (vd));
        andadores.push_front(this);
    }
    Andador::~Andador()
    {
        andadores.remove(this);
    }
    void Andador::escreverDados(ofstream& stream)
    {
        int tam = andadores.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto andador : andadores)
        {
            andador->escreverDadosPessoal(stream);
        }
    }
    void Andador::lerDados(ifstream& stream, Cena* cena)
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
            cerr<<"Impossivel abrir dados dos Andadores"<<endl;
        }
        
        
    }
}