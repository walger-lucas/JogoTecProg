#include "ChefaoPulador.h"
#include "Cena.h"
#include "NuvemAcoelhada.h"
namespace Entidades
{
    int ChefaoPulador::id=0;

    list<ChefaoPulador*> ChefaoPulador::puladores= list<ChefaoPulador*>();

    const string ChefaoPulador::TAG_CHEFAO = "chefao";

    ChefaoPulador::ChefaoPulador(Vector2f posicao)
    :Personagem("chefe"+to_string(id++)),
    cCP(new ControleChefaoPulador())
    {
        vd = new Vida(1);
        pos = new Posicao(posicao.x,posicao.y);
        cR = new CorpoRigido(true,true,true);
        gS = nullptr;
        textura.loadFromFile("Arquivos/Imagens/chefeDir.png");
        this->pos->setEscala(Vector2f(0.5,0.5));
        gS = new GraficoSprite(&textura,1,false);
        addComponente(vd);
        addComponente(this->pos);
        addComponente(cR);
        addComponente(gS);
        addComponente(cCP);
        addTag(TAG_CHEFAO);
        puladores.push_front(this);
    }
    ChefaoPulador::~ChefaoPulador()
    {
        puladores.remove(this);
        if(puladores.empty())
        {
            NuvemAcoelhada::AbrirPortal();
        }
    }
    void ChefaoPulador::Carregar()
    {
        Vector2f dim = gS->getSprite()->getDim();
        Vector2f esc =gS->getSprite()->getEscala();
        cR->setDim(Vector2f(dim.x*esc.x,dim.y*esc.y));
    }
    void ChefaoPulador::escreverDadosPessoal(ofstream& stream)
    {
        //dados lidos em ordem: tam do nome, nome,Vida,Posicao,Velocidade,direcao, recarga,tempo,
        int vidas = this->vd->getVida();
        Vector2f pos = this->pos->getPos();
        Vector2f vel = this->cR->getVelocidade();
        bool dir = this->cCP->getIndoDireita();
        float rec = this->cCP->getTempoRec(); 
        float cont = this->cCP->getTempoCont(); 
        int size = this->getNome().length();
        stream.write((char*)&size,sizeof(int));
        stream.write(this->getNome().data(),sizeof(char)*size); 
        stream.write((char*)&vidas,sizeof(int));
        stream.write((char*)&pos.x,sizeof(float));
        stream.write((char*)&pos.y,sizeof(float));
        stream.write((char*)&vel.x,sizeof(float));
        stream.write((char*)&vel.y,sizeof(float));
        stream.write((char*)&dir,sizeof(bool));
        stream.write((char*)&rec,sizeof(float));
        stream.write((char*)&cont,sizeof(float));
    }
    void ChefaoPulador::escreverRelacoesPessoal(ofstream& stream)
    {
        //dados escritos em ordem: Nome,NomeBaixo,Nome Cima
        int size = this->getNome().length();
        stream.write((char*)&size,sizeof(int));
        stream.write(this->getNome().data(),sizeof(char)*size); 
        if(this->cCP->getCima())//guardar nome do chefe de cima
        {
            std::string nome = this->cCP->getCima()->getEntidade()->getNome();
            size = nome.length();
            stream.write((char*)&size,sizeof(int));
            stream.write(nome.data(),sizeof(char)*size); 
        }
        else
        {
            size=-1;
            stream.write((char*)&size,sizeof(int));
        }
        if(this->cCP->getBaixo())//guardar nome do chefe de cima
        {
            std::string nome = this->cCP->getBaixo()->getEntidade()->getNome();
            size = nome.length();
            stream.write((char*)&size,sizeof(int));
            stream.write(nome.data(),sizeof(char)*size); 
        }
        else
        {
            size=-1;
            stream.write((char*)&size,sizeof(int));
        }

    }
    void ChefaoPulador::lerRelacoesPessoal(ifstream& stream,Cena* cena)
    {
        //dados escritos em ordem: Nome,NomeBaixo,Nome Cima
        int size;
        stream.read((char*)&size,sizeof(int));
        char* nomeC = new char[size];
        stream.read(nomeC,sizeof(char)*size);
        ControleChefaoPulador* ccp = (*cena)[nomeC]->getComponente<ControleChefaoPulador>();
        delete [] nomeC;
        stream.read((char*)&size,sizeof(int));
        if(size==-1)
            ccp->setCima(nullptr);
        else
        {
            nomeC = new char[size];
            stream.read(nomeC,sizeof(char)*size); 
            ccp->setCima((*cena)[nomeC]->getComponente<ControleChefaoPulador>());
            delete [] nomeC;
        }
        stream.read((char*)&size,sizeof(int));
        if(size==-1)
            ccp->setBaixo(nullptr);
        else
        {
            nomeC = new char[size];
            stream.read(nomeC,sizeof(char)*size); 
            ccp->setBaixo((*cena)[nomeC]->getComponente<ControleChefaoPulador>());
            delete [] nomeC;
        }

    }
    
    void ChefaoPulador::lerDadosPessoal(ifstream& stream, Cena* cena)
    {
        //dados lidos em ordem: tam do nome, nome,Vida,Posicao,Velocidade,direcao, recarga,tempo,
        int vidas;
        Vector2f pos;
        Vector2f vel;
        bool dir;
        float rec;
        float cont;
        int size;
        stream.read((char*)&size,sizeof(int));
        char* nomeC = new char[size];
        stream.read(nomeC,sizeof(char)*size);
        stream.read((char*)&vidas,sizeof(int));
        stream.read((char*)&pos.x,sizeof(float));
        stream.read((char*)&pos.y,sizeof(float));
        stream.read((char*)&vel.x,sizeof(float));
        stream.read((char*)&vel.y,sizeof(float));
        stream.read((char*)&dir,sizeof(bool));
        stream.read((char*)&rec,sizeof(float));
        stream.read((char*)&cont,sizeof(float));
        ChefaoPulador * chef = new ChefaoPulador(pos);
        chef->setNome(nomeC);
        chef->cCP->setIndoDireita(dir);
        chef->cCP->setTempoCont(cont);
        chef->cCP->setTempoRec(rec);
        *cena+= chef;
        chef->cR->setVelocidade(vel);
        delete [] nomeC;
    }
        void ChefaoPulador::escreverDados(ofstream& stream)
    {
        int tam = puladores.size();
        stream.write((char*)&tam,sizeof(int));
        //escreve dados internos dos puladores
        for(auto pulador : puladores)
        {
            pulador->escreverDadosPessoal(stream);
        }
        //escreve relacoes entre objetos dos chefes puladores
        for(auto pulador : puladores)
        {
            pulador->escreverRelacoesPessoal(stream);
        }
    }
    void ChefaoPulador::lerDados(ifstream& stream, Cena* cena)
    {
        int tam;
        try
        {
            stream.read((char*)&tam,sizeof(int));
            for(int i =0;i<tam;i++)
            {
                lerDadosPessoal(stream,cena);
            }
            for(int i =0;i<tam;i++)
            {
                lerRelacoesPessoal(stream,cena);
            }
            if(tam==0)
            {
                NuvemAcoelhada::AbrirPortal();
            }
        }
        catch(const std::ifstream::failure &e)
        {
            cerr<<"Impossivel abrir dados dos Chefoes Puladores"<<endl;
        }
        
        
    }
}