#include "NuvemAcoelhada.h"
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
#include "Seiva.h"
#include "ChefaoPulador.h"
using namespace Entidades;
namespace Cenas
{
    Portal* NuvemAcoelhada::portal = nullptr;
    void NuvemAcoelhada::PortalFunc()
    {
    }
    void NuvemAcoelhada::AbrirPortal()
    {
        if(portal)
            portal->AbrirPortar(true);
    }
    void NuvemAcoelhada::Carregar()
    {
        *this+= new Background(Vector2f(0,7),14,"background2.png");
        portal = new Portal(Vector2f(19,3),std::bind(&NuvemAcoelhada::PortalFunc,this),false);
        *this+=portal;
        //instancializa chao
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(16.3*i,-5),"PlataformaNuvem.png"));
        //instancializa plataforma primeiro nivel
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(4+16*i,-2),"PlataformaNuvem.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        //instancializa plataforma segundo nivel
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(9+14*i,1),"PlataformaNuvem.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        //instancializa plataforma terceiro nivel
        for(int i =0;i<2;i++)
            AdicionarEntidade(new Plataforma(Vector2f(1+14*i,4),"PlataformaNuvem.png",Vector2f(0,0),Vector2f(0.5,0.5)));
        

        
        //instancia barreiras limitadoras de cenario
        AdicionarEntidade(new Plataforma(Vector2f(-1,100),"cubo.png",Vector2f(0,0),Vector2f(1,200)));
        AdicionarEntidade(new Plataforma(Vector2f(32,100),"cubo.png",Vector2f(0,0),Vector2f(1,200)));
        *this+= new ControladorUI(7,-6,32,0,3);
        if(Configs::Salvador::salvador->getIdSaveAtual()==-1)
        {
            //Carregamento Jogadores
            Jogador* j = new Jogador(Vector2f(2,-2),true,Jogador::getVidas(0));
            AdicionarEntidade(j);
            if(Jogador::SaoDoisJogadores())
                *this += new Jogador(Vector2f(1,-2),false,Jogador::getVidas(1));
            int seiva = 3 + rand()%3;
            for(int i=0 ; i<seiva;i++)
            {
                *this += new Seiva(Vector2f(5+(((float)rand())/RAND_MAX)*24,-4.6));
            }
            int creatures = 3+ rand()%5;
            for(int i=0;i<creatures;i++)
            {
                *this+= new Andador(Vector2f(5+(((float)rand())/RAND_MAX)*24,-3));
            }
            creatures = rand()%5;
            for(int i=0;i<creatures;i++)
            {
                *this+= new Andador(Vector2f(5+(((float)rand())/RAND_MAX)*24,5));
            }
            for(int i =0;i<2;i++)
            {
                int espinhos = 1+ rand()%2;
                for(int j=0;j<espinhos;j++)
                    *this+= new Espinho(Vector2f(4+16*i+(((float)rand())/RAND_MAX)*8,0));
                espinhos = 1+ rand()%2;
                for(int j=0;j<espinhos;j++)
                    *this+= new Espinho(Vector2f(9+14*i+(((float)rand())/RAND_MAX)*8,3));
            }
            //invoca bosses
            int coelo = 6 + rand()%10;
            for(int i=0 ; i<coelo;i++)
            {
               *this+= new ChefaoPulador(Vector2f(10+(((float)rand())/RAND_MAX)*15,(((float)rand())/RAND_MAX)*8-3));
            }

        }
        else
        {
            Configs::Salvador::salvador->carregarCena(this);
        }
        
    }
}