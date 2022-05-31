#include "Jogo.h"
using namespace Gerenciadores;


void Jogo::Loop()
{
    GerenciadorGrafico render=GerenciadorGrafico(window);
    GerenciadorCenas gerCenas=GerenciadorCenas();
    GerenciadorInputs gerInput=GerenciadorInputs();
    GerenciadorColisoes fisica=GerenciadorColisoes();
    
    gerInput.setWindowAtual(window);
    gerCenas.setCena(0);
    while(window->isOpen())
    {
        tempo.atualizaDeltaTempo();

        gerInput.PollEvents();

        gerCenas.Atualizar();
       
        
        tempoUltAtualizacaoFisica+=Tempo::getDeltaTempo();
        //faz a simulacao fisica a cada deltaTempoFixoSegundos
        if(tempoUltAtualizacaoFisica/(float)atualizacaoMax > Tempo::getDeltaTempoFixo())//if(tempoUltAtualizacao/atualizacaoMax > Tempo::getDeltaTempoFixo())
        {
            tempoUltAtualizacaoFisica =0;
        }
        else
        {
            int vezes = tempoUltAtualizacaoFisica/Tempo::getDeltaTempoFixo();//Tempo::getDeltaTempoFixo();
            for(int i=0;i<vezes;i++)
            {
                fisica.ResolverColisoes();
                gerCenas.AtualizarFixo();
                tempoUltAtualizacaoFisica -=Tempo::getDeltaTempoFixo();
            }
                
        }
        //Faz a renderizacao a cada Tempo Render segundos
        tempoUltRender+=Tempo::getDeltaTempo();
        if(tempoUltRender>Tempo::getTempoRender())
        {
            render.Render();
            gerCenas.Render();
            tempoUltRender=0;
        }
        
    }
    
}

Jogo::Jogo()
:window(nullptr),tempo(),tempoUltAtualizacaoFisica(0)
,tempoUltRender(0),atualizacaoMax(10)
{
    window = new RenderWindow(VideoMode(800,800),"HeyListen",Style::Titlebar | Style::Close |Style::Resize);
    window->setFramerateLimit(10000);
    Loop();
            
}
Jogo::~Jogo()
{
    delete window;
}
