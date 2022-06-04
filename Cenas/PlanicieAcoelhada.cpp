#include "PlanicieAcoelhada.h"
#include "Plataforma.h"
#include "ControladorUI.h"
#include "Salvador.h"
#include "Andador.h"
#include "Explodidor.h"
#include "Trampolim.h"
#include "Espinho.h"
#include "BackGround.h"
#include "GerenciadorCenas.h"
#include "Portal.h"
using namespace Entidades;
namespace Cenas
{
    void PlanicieAcoelhada::PortalFunc()
    {
        Jogador::salvarVidas();
        GerenciadorCenas::ProximaCena(1);
    }
    void PlanicieAcoelhada::Carregar()
    {
        
        *this+= new Background(Vector2f(0,13),18,"background1.png");
        //instancializa chao
        for(int i =0;i<4;i++)
            AdicionarEntidade(new Plataforma(Vector2f(16.3*i,-5),"Plataforma.png"));
        //instancializa plataforma primeiro nivel
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(3+25*i,-2),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        //instancializa plataforma segundo nivel
        for(int i =0;i<3;i++)
            AdicionarEntidade(new Plataforma(Vector2f(7+16*i,1),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        //instancializa plataforma terceiro nivel
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(12+27*i,4),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        //instancializa plataforma quarto nivel
        for(int i =0;i<3;i++)
            AdicionarEntidade(new Plataforma(Vector2f(1+18*i,7),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        AdicionarEntidade(new Plataforma(Vector2f(20,10),"Plataforma.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        *this+= new Portal(Vector2f(23,12.6),std::bind(&PlanicieAcoelhada::PortalFunc,this),true);
        
        //instancia barreiras limitadoras de cenario
        AdicionarEntidade(new Plataforma(Vector2f(-1,100),"cubo.png",Vector2f(0,0),Vector2f(1,200)));
        AdicionarEntidade(new Plataforma(Vector2f(48,100),"cubo.png",Vector2f(0,0),Vector2f(1,200)));
        *this+= new ControladorUI(13,-6,48,0,3);
        if(Configs::Salvador::salvador->getIdSaveAtual()==-1)
        {
            //Carregamento Jogadores
            Jogador* j = new Jogador(Vector2f(2,-2),true);
            AdicionarEntidade(j);
            if(Jogador::SaoDoisJogadores())
                *this += new Jogador(Vector2f(1,-2),false);
            //Carregamento criaturas, nivel terreo Andadores
            for (int j=0;j<3;j++)
            {
                int creatures = 2+rand()%3;
                for(int i=0;i<creatures;i++)
                {
                    *this+= new Andador(Vector2f(5+13*j+(((float)rand())/RAND_MAX)*8,-3));
                }
                int explodidores = rand()%2;
                for (int i =0;i<explodidores;i++)
                {
                     *this+= new Explodidor(Vector2f(13+13*j+(((float)rand())/RAND_MAX)*5,-3));
                }
            }
            for(int j =0;j<2;j++)
            {
                int trampolim = 1+ rand()%2;
                for(int i =0;i<trampolim;i++)
                {
                    *this+=new Trampolim(Vector2f(8+18*j+(((float)rand())/RAND_MAX)*18,-3));
                }
            }
            //Carregamento Criaturas, primeiro nivel
            for(int i =0;i<2;i++)
            {
                int explodidores = 1 +rand()%2;
                for(int j=0;j<explodidores;j++)
                    *this+= new Explodidor(Vector2f(3+25*i+(((float)rand())/RAND_MAX)*8,0));
                int espinhos = 1+ rand()%3;
                for(int j=0;j<espinhos;j++)
                    *this+= new Espinho(Vector2f(3+25*i+(((float)rand())/RAND_MAX)*8,0));
            }
            //Carregamento Criaturas e Obstaculos segundo nivel
            //criar obstaculos e explodidor faltante para obrigar a existencia de ao menos 3 de cada instancia
                *this+=new Trampolim(Vector2f(7+16*(rand()%3)+(((float)rand())/RAND_MAX)*8,3));
                *this+=new Trampolim(Vector2f(7+16*(rand()%3)+(((float)rand())/RAND_MAX)*8,3));
            int andadores = 3+rand()%6;
            for(int i =0;i<andadores;i++)
            {
                *this+= new Andador(Vector2f(7+16*(rand()%3)+(((float)rand())/RAND_MAX)*8,3));
            }
            int espinho = 2+ rand()%3;
            for(int i =0;i<espinho;i++)
            {
                *this+= new Espinho(Vector2f(7+16*(rand()%3)+(((float)rand())/RAND_MAX)*8,3));
            }
            int explodidores = 2+ rand()%3;
            for(int i =0;i<explodidores;i++)
            {
                *this+= new Explodidor(Vector2f(7+16*(rand()%3)+(((float)rand())/RAND_MAX)*8,3));
            }
            //Instancia Criaturas e obstaculos 3 nivel
            for(int i=0;i<2;i++)
            {
                explodidores = 1+ rand()%3;
                for(int j =0;j<explodidores;j++)
                {
                    *this+= new Explodidor(Vector2f(12+27*i+(((float)rand())/RAND_MAX)*8,6));
                }
            }
            *this+=new Trampolim(Vector2f(12+27*(rand()%2)+(((float)rand())/RAND_MAX)*8,6));
            //Instancia criaturas e obstaculos 4 nivel
            for(int i=0;i<3;i++)
            {
                explodidores = rand()%3;
                for(int j =0;j<explodidores;j++)
                {
                    *this+= new Explodidor(Vector2f(1+18*i+(((float)rand())/RAND_MAX)*8,10));
                }
                andadores =explodidores = rand()%3;
                for(int j =0;j<andadores;j++)
                {
                    *this+= new Andador(Vector2f(1+18*i+(((float)rand())/RAND_MAX)*8,10));
                }

            }
            espinho = 2+ rand()%3;
            for(int i =0;i<espinho;i++)
            {
                *this+= new Espinho(Vector2f(1+18*(rand()%3)+(((float)rand())/RAND_MAX)*8,10));
            }

        }
        else
        {
            Configs::Salvador::salvador->carregarCena(this);
        }
        
    }
}