#include "MenuVencer.h"
#include "Cena.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPrincipal.h"
#include "Salvador.h"
#include "Lideranca.h"


MenuVencer::~MenuVencer()
{
    if(menu)
        menu->Destruir();
    if(nomeB)
        nomeB->Destruir();
    if(lider)
        lider->Destruir();

    
}
void MenuVencer::Iniciar()
{
    Tempo::Pausar(true);
    nomeB = new BotaoEntidade(Vector2f(3.5,-0.5),0.3,"Escreva seu Nome",Vector2f(-30,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuVencer::Nome,this),nullptr);
    lider = new BotaoEntidade(Vector2f(3.5,-3.9),0.3,"Adicionar no Placar",Vector2f(-20,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuVencer::Lider,this),nullptr);
    menu= new BotaoEntidade(Vector2f(3.5,-2.8),0.3,"Voltar ao Menu",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuVencer::VoltaMenu,this),nullptr);
    
    entidades.Adicionar(nomeB);
    entidades.Adicionar(lider);
    entidades.Adicionar(menu);

}
void MenuVencer::VoltaMenu()
{
    Jogo::MenuAtual(new MenuPrincipal());
    GerenciadorCenas::ProximaCena(-1);
}


void MenuVencer::Nome()
{
    nomeApertado=!nomeApertado;
    if(nomeApertado)
    {
        GerenciadorInputs::cleanInputText();
        nomeB->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);
    }
    else
    {
        nomeB->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
    }
        
}


void MenuVencer::Atualizar()
{
    if(nomeApertado)
    {
        nome = GerenciadorInputs::getInputText();
        int size =nome.size();
        if(size>14)
        {
            nome.resize(14);
            size=14;
        }
        for(int i =0;i<size;i++)
        {
            if(nome[i]=='\n')
            {
                nome.resize(i);
                nomeApertado=false;
                nomeB->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
                GerenciadorInputs::cleanInputText();
                break;
            }
        }
        nomeB->setTexto(nome);
    }

}
void MenuVencer::Lider()
{
    if(nome!="")
    {
        Lideranca::addLider(nome,Jogador::getPontos());
        VoltaMenu();
    }
}