#include"GerenciadorColisoes.h"
#include"ObjetoFisico.h"
#include"commons.h"
using namespace sf;
using namespace std;
using namespace Colisoes;
namespace Gerenciadores{
    float GerenciadorColisoes::tempoUltAtualizacao(0.0F);
    list<ObjetoFisico*> GerenciadorColisoes::objetos=list<ObjetoFisico*>();
    const int GerenciadorColisoes::atualizacaoMax(10);
    const float GerenciadorColisoes::tempoFixo(1/80.0); //remover quando adicionado tempo
    const float GerenciadorColisoes::gravidade(3);
    
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
        list<ObjetoFisico*> colisoes= list<ObjetoFisico*>();
        colisoes.clear();
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            tenteDestruir(it);
            if(it!=objetos.end()&&Colisor::Colide((*it)->getColisor(),ponto))
            {
                colisoes.push_back(*it);
            }
        }
        return colisoes;
    }
    list<ObjetoFisico*> GerenciadorColisoes::EncontraColisao(Colisor& colisor)
    {
        list<ObjetoFisico*> colisoes= list<ObjetoFisico*>();
        colisoes.clear();
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            tenteDestruir(it);
            if( it!=objetos.end()&&Colisor::Colide((*it)->getColisor(),colisor))
            {
                colisoes.push_back(*it);
            }
        }
        return colisoes;
    }
    void GerenciadorColisoes::Atualizar()
    {
        /* Ainda não feito
        tempoUltAtualizacao += Tempo::getDeltaTime();
        */   
       if(tempoUltAtualizacao/atualizacaoMax > tempoFixo)//if(tempoUltAtualizacao/atualizacaoMax > Tempo::getDeltaTempoFixo())
       {
           tempoUltAtualizacao =0;
       }
       else
       {
           int vezes = tempoUltAtualizacao/tempoFixo;//Tempo::getDeltaTempoFixo();
           for(int i=0;i<vezes;i++)
                ResolverColisoes();
       }
    }
    void GerenciadorColisoes::ResolverColisoes()
    {
        //remove objetos com destruir setado para true atualiza posicao
        for(auto it = objetos.begin();it!= objetos.end();it++)
        {
            tenteDestruir(it);
            if(it!=objetos.end())
            {
                if(!(*it)->getCinematico())
                {
                    (*it)->setVel(Vector2f(0,0));
                    
                }
                (*it)->AtualizarPos();
            }
        }
        //compara todos sem comparar duas vezes, entao atualiza o objeto
        for(auto ob = objetos.begin();ob!= objetos.end();ob++)
        {
            for(auto ob2 = next(ob);ob2!=objetos.end();ob2++)
            {
                
                ObjetoFisico::Resolver(**ob,**ob2);
            }
        }
    }
    
}