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
#include "ControladorUI.h"
#include "Espinho.h"
#include "Trampolim.h"
#include "Salvador.h"
#include "Seiva.h"
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
            AdicionarEntidade(new Plataforma(Vector2f(16.3*i,-5),"Plataforma.png"));
        for(int i =0;i<2;i++)
        AdicionarEntidade(new Plataforma(Vector2f(3+25*i,-2),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        AdicionarEntidade(new Plataforma(Vector2f(-1,50),"cubo.png",Vector2f(0,0),Vector2f(1,200)));
        AdicionarEntidade(new Plataforma(Vector2f(48,50),"cubo.png",Vector2f(0,0),Vector2f(1,200)));



        int esp = 3+ rand()%3;
        for(int i=0 ; i<esp;i++)
        {
            *this += new Espinho(Vector2f(5+(((float)rand())/RAND_MAX)*40,-4.5));
        }
        int tramp = 1 + rand()%3;
        for(int i=0 ; i<tramp;i++)
        {
            *this += new Trampolim(Vector2f(5+(((float)rand())/RAND_MAX)*40,-4.5));
        }
        
        int gosma = 1 + rand()%2;
        for(int i=0 ; i<gosma;i++)
        {
            *this += new Seiva(Vector2f(5+(((float)rand())/RAND_MAX)*40,-4.6));
        }
        
        //AdicionarEntidade(new BotaoEntidade(Vector2f(1,-2),0.3,"Botao Teste",Vector2f(-40,-25),"button0.png","ARIAL.TTF",std::bind(&CenaTeste::apt,this),std::bind(&CenaTeste::dapt,this)));
        if(Configs::Salvador::salvador->getIdSaveAtual()==-1)
        {
            int creatures = 7+rand()%6;
            for(int i=0;i<creatures;i++)
            {
                *this+= new Andador(Vector2f(5+(((float)rand())/RAND_MAX)*40,5));
            }
            int explodidores = 4+rand()%3;
            for(int i=0;i<explodidores;i++)
            {
                *this+= new Explodidor(Vector2f(4+(((float)rand())/RAND_MAX)*40,2));
            }

            Jogador* j = new Jogador(Vector2f(2,-2),true);
            AdicionarEntidade(j);
            if(Jogador::SaoDoisJogadores())
                *this += new Jogador(Vector2f(1,-2),false);
        
        }
        else
        {
            Configs::Salvador::salvador->carregarCena(this);
        }
        *this+= new ControladorUI(1.5,-6,48,0,2);
        
    
        

    }
}