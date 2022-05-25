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
using namespace sf;
using namespace std;


namespace Cenas
{
    void CenaTeste::apt()
    {
        cout<< "botao apertado"<<endl;
        *this+= new Andador(Vector2f(2,-2));
    }
    void CenaTeste::dapt()
    {
        cout<< "botao desapertado"<<endl;
    }

    void CenaTeste::Carregar()
    {
        
        for(int i =0;i<3;i++)
            AdicionarEntidade(new Plataforma(Vector2f(16.2*i,-5),"Plataforma.png"));
        

        

        

    
        AdicionarEntidade(new BotaoEntidade(Vector2f(1,-2),0.3,"Botao Teste",Vector2f(-40,-25),"button0.png","ARIAL.TTF",std::bind(&CenaTeste::apt,this),std::bind(&CenaTeste::dapt,this)));
        Jogador* j = new Jogador(Vector2f(2,-2));
        AdicionarEntidade(j);
        
    
        

    }
}