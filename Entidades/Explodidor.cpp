#include "Explodidor.h"
#include "Cena.h"
namespace Entidades
{
    list<Explodidor*> Explodidor::explodidores= list<Explodidor*>();
    void Explodidor::escreverDadosPessoal(ofstream& stream)
    {
        //dados escritos em ordem: Vida,cooldownVida,cooldownProjetil,Posicao,Velocidade,direcao
        int vidas = this->vd->getVida();
        float cooldownVida= this->vd->getTempoAtualCooldown();
        float proj = this->cE->getRecarga();
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        bool dir = this->cE->getIndoDireita();
        stream.write((char*)&vidas,sizeof(int));
        stream.write((char*)&cooldownVida,sizeof(float));
        stream.write((char*)&proj,sizeof(float));
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
        stream.write((char*)&dir,sizeof(bool));
    }
    void Explodidor::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados lidos em ordem: Vida,cooldown Vida,recarga,Posicao,Velocidade,direcao
        int vidas;
        float cooldownVida,rec;
        Vector2f pos;
        Vector2f vel;
        bool dir;
        stream.read((char*)&vidas,sizeof(int));
        stream.read((char*)&cooldownVida,sizeof(float));
        stream.read((char*)&rec,sizeof(float));
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        stream.read((char*)&dir,sizeof(bool));
        Explodidor* exp = new Explodidor(pos);
        *cena+=exp;
        exp->vd->setVida(vidas);
        exp->vd->setTempoAtualCooldown(cooldownVida);
        exp->cE->setRecarga(rec);
        exp->cR->setVelocidade(vel);
        exp->cE->setIndoDireita(dir);

    }
    void Explodidor::Carregar(){
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));

    }
    Explodidor::Explodidor(Vector2f posicao)
    : Personagem("Explodidor"),
    cE(new ControleExplodidor())
    {
        pos = new Posicao(posicao.x,posicao.y);
        gS = nullptr;
        cR = new CorpoRigido(true,true,true);
        vd = new Vida(3,0.3);
        textura.loadFromFile("Arquivos/Imagens/Explodidor_A.png");
        pos->setEscala(Vector2f(1.5,1.5));
        gS =new GraficoSprite(&textura,0,false);
        this->addComponente(static_cast<Componente*> (pos));
        this->addComponente(static_cast<Componente*> (gS));
        this->addComponente(static_cast<Componente*> (cR));
        this->addComponente(static_cast<Componente*> (cE));
        this->addComponente(static_cast<Componente*> (vd));
        explodidores.push_front(this);
    }
    Explodidor::~Explodidor()
    {
        explodidores.remove(this);
    }
    void Explodidor::escreverDados(ofstream& stream)
    {
        int tam = explodidores.size();
        stream.write((char*)&tam,sizeof(int));
        for(auto explodidor : explodidores)
        {
            explodidor->escreverDadosPessoal(stream);
        }
    }
    void Explodidor::lerDados(ifstream& stream, Cena* cena)
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
            cerr<<"Impossivel abrir dados dos Explodidores"<<endl;
        }
        
        
    }
}