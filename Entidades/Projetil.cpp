#include "Projetil.h"
#include "Jogador.h"
#include "Cena.h"
namespace Entidades{
    const string Projetil::TAG_PROJETIL = "projetil";
        list<Projetil*> Projetil::projeteis= list<Projetil*>();
    void Projetil::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem:Posicao, tam,Velocidade

        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        float tam = this->pos->getEscala().x;
        int dano = this->dano;
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&tam,sizeof(float));
        stream.write((char*)&dano,sizeof(int));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));

    }
    void Projetil::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados lidos em ordem: Posicao,Velocidade
        Vector2f pos;
        float tam;
        int dano;
        Vector2f vel;
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&tam,sizeof(float));
        stream.read((char*)&dano,sizeof(int));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        Projetil* p = new Projetil(pos,vel,dano,tam);
        *cena+=p;

    }
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
        projeteis.push_front(this);

    }
    Projetil::~Projetil()
    {
        projeteis.remove(this);
    }
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
            if(cp &&cp->getEntidade()->temTag(Jogador::TAG_JOGADOR))
                cp->getEntidade()->getComponente<Vida>()->Machucar(dano);
            Destruir();
        }
    }
    void Projetil::escreverDados(ofstream& stream)
    {
        int tam = projeteis.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto projetil : projeteis)
        {
            projetil->escreverDadosPessoal(stream);
        }
    }
    void Projetil::lerDados(ifstream& stream, Cena* cena)
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
            cerr<<"Impossivel abrir dados dos Projeteis"<<endl;
        }
        
        
    }
}