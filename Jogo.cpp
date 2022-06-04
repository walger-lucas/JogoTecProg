#include "Jogo.h"
#include "MenuPrincipal.h"
using namespace Gerenciadores;
Menu* Jogo::menuAtual = nullptr;
Menu* Jogo::proxMenu = nullptr;

void Jogo::Loop()
{
    MenuAtual(new MenuPrincipal());
    while(window->isOpen())
    {
        tempo.atualizaDeltaTempo();

        gerInput.PollEvents();
        
        gerCenas.Atualizar();
        if(menuAtual)
            menuAtual->Atualizar();
       
        if(!Tempo::Pausado())
        {
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
        }
        //Faz a renderizacao a cada Tempo Render segundos
        tempoUltRender+=Tempo::getDeltaTempo();
        if(tempoUltRender>Tempo::getTempoRender())
        {
            render.Render();
            gerCenas.Render();
            tempoUltRender=0;
        }
        if(proxMenu!=menuAtual)
        {
            if(menuAtual)
                delete menuAtual;
            menuAtual = proxMenu;
            if(menuAtual)
                menuAtual->Iniciar();
        }
        
    }
    
}

Jogo::Jogo()
:window(nullptr),tempo(),tempoUltAtualizacaoFisica(0)
,tempoUltRender(0),atualizacaoMax(10)
{
    srand(time(NULL));
    window = new RenderWindow(VideoMode(800,800),"HeyListen",Style::Titlebar | Style::Close |Style::Resize);
    window->setFramerateLimit(10000);
    render.setWindow(window);
    gerInput.setWindowAtual(window);
    Loop();
            
}
Jogo::~Jogo()
{
    if(menuAtual)
        delete menuAtual;
    delete window;
}
void Jogo::MenuAtual(Menu* menu)
{
    proxMenu = menu;
}
