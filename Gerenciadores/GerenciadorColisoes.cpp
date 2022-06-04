#include"GerenciadorColisoes.h"
#include"ObjetoFisico.h"
#include"commons.h"
#include"Tempo.h"
using namespace sf;
using namespace std;
using namespace Colisoes;
using namespace Configs;
namespace Gerenciadores{
    list<ObjetoFisico*> GerenciadorColisoes::objetos=list<ObjetoFisico*>();
    const float GerenciadorColisoes::gravidade(9);
    
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

    void GerenciadorColisoes::ResolverColisoes()
    {
        //remove objetos com destruir setado para true atualiza posicao
        auto it =objetos.begin();
        while(it!=objetos.end())
        {
            if(!tenteDestruir(it))
            {

                if(!(*it)->getCinematico())
                {
                    (*it)->setVel(Vector2f(0,0));
                    
                }
                (*it)->AtualizarPos();
                it++;
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