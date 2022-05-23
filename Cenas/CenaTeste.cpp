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
using namespace sf;
using namespace std;
Posicao* posit;
    void apt()
    {
        cout<< "botao apertado"<<endl;
        posit->setPos(Vector2f(0,0));
    }
    void dapt()
    {
        cout<< "botao desapertado"<<endl;
    }
namespace Cenas
{

    void CenaTeste::Carregar()
    {
        Plataforma* plat=new Plataforma(Vector2f(0,-5.1),"ground",Vector2f(0,10));
        
        AdicionarEntidade(plat);
        

        



    
        AdicionarEntidade(new BotaoEntidade(Vector2f(1,-2),0.3,"Botao Teste",Vector2f(-40,-25),"button0","arial",apt,dapt));
        Jogador* j = new Jogador(Vector2f(2,-2));
        AdicionarEntidade(j);
        posit = j->getComponente<Posicao>();
        
    
        

    }
}