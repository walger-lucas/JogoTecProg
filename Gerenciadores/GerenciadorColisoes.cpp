#include"GerenciadorColisoes.h"
#include"commons.h"
using namespace sf;
using namespace std;
using namespace Colisoes;
namespace Gerenciadores{
    float GerenciadorColisoes::tempoUltAtualizacao(0.0F);
    list<ObjetoFisico*> GerenciadorColisoes::objetos=list<ObjetoFisico*>();
    const int GerenciadorColisoes::atualizacaoMax(10);
    const float GerenciadorColisoes::tempoFixo(1/80.0);
    
    void GerenciadorColisoes::AddObjeto(ObjetoFisico* objeto)
    {
        if(objeto != nullptr)
            objetos.push_back(objeto);
    }
    //retorna true se objeto destruido
    bool GerenciadorColisoes::tenteDestruir(list<ObjetoFisico*>::iterator& it)
    {
        if((*it)->getDestruir())
        {
            delete *it;
            objetos.erase(it++);
            return true;
        }
        return false;
    }
    list<ObjetoFisico*> GerenciadorColisoes::EncontraColisao(Vector2f ponto)
    {
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            if(!tenteDestruir(it) && it!=objetos.end())
            {
                Colisor::Colide((*it)->getColisor(),ponto);
            }
        }
    }
    list<ObjetoFisico*> GerenciadorColisoes::EncontraColisao(Colisor& colisor)
    {
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            if(!tenteDestruir(it) && it!=objetos.end())
            {
                Colisor::Colide((*it)->getColisor(),colisor);
            }
        }
    }
    void GerenciadorColisoes::Atualizar()
    {
        /* Ainda não feito
        tempoUltAtualizacao += Tempo::getDeltaTime();
        */   
       if(tempoUltAtualizacao/atualizacaoMax > tempoFixo)
       {
           tempoUltAtualizacao =0;
       }
       else
       {
           int vezes = tempoUltAtualizacao/tempoFixo;
           for(int i=0;i<vezes;i++)
                ResolverColisoes();
       }
    }
    void GerenciadorColisoes::ResolverColisoes()
    {
        //remove objetos com destruir setado para true
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            tenteDestruir(it);
        }
        //compara todos sem comparar duas vezes, entao atualiza o objeto
        for(auto ob = objetos.begin();ob!= objetos.end();ob++)
        {
            for(auto ob2 = next(ob);ob2!=objetos.end();ob2++)
            {
                ObjetoFisico::Resolver(**ob,**ob2);
            }
            (*ob)->Atualizar();
        }
    }
    
}