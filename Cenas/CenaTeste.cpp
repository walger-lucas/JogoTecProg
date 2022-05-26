#include "CenaTeste.h"
#include"Entidade.h"
#include"Posicao.h"
#include"Jogador.h"
#include"commons.h"
#include"BotaoEntidade.h"
#include"GerenciadorColisoes.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorInputs.h"
#include "BotaoEntidade.h"
#include "commons.h"
#include "Plataforma.h"
#include "Andador.h"
#include "Explodidor.h"
#include "Projetil.h"
using namespace sf;
using namespace std;


namespace Cenas
{
    void CenaTeste::apt()
    {
        cout<< "botao apertado"<<endl;
        *this+= new Explodidor(Vector2f(2,-2));
    }
    void CenaTeste::dapt()
    {
        cout<< "botao desapertado"<<endl;
    }

    void CenaTeste::Carregar()
    {
        srand(time(NULL));
        for(int i =0;i<4;i++)
            AdicionarEntidade(new Plataforma(Vector2f(16.2*i,-5),"Plataforma.png"));
        for(int i =0;i<2;i++)
        AdicionarEntidade(new Plataforma(Vector2f(3+25*i,-2.4),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));

        int creatures = 8+rand()%10;
        for(int i=0;i<creatures;i++)
        {
            *this+= new Andador(Vector2f((((float)rand())/RAND_MAX)*48,5));
        }
        int explodidores = 4+rand()%3;
        for(int i=0;i<explodidores;i++)
        {
            *this+= new Explodidor(Vector2f(4+(((float)rand())/RAND_MAX)*48,2));
        }
        //AdicionarEntidade(new BotaoEntidade(Vector2f(1,-2),0.3,"Botao Teste",Vector2f(-40,-25),"button0.png","ARIAL.TTF",std::bind(&CenaTeste::apt,this),std::bind(&CenaTeste::dapt,this)));
        Jogador* j = new Jogador(Vector2f(2,-2),false);
        AdicionarEntidade(j);
        
    
        

    }
}