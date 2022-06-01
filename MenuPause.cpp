#include "MenuPause.h"
#include "MenuNovoJogo.h"
#include "MenuPrincipal.h"
#include "Tempo.h"
#include "Menu.h"
#include "Jogo.h"

MenuPause::~MenuPause()
{
    if(voltarJogo)
        voltarJogo->Destruir();
    if(voltarMenu)
        voltarMenu->Destruir();
    if(salvar)
        salvar->Destruir();
}
void MenuPause::Iniciar()
{
    Tempo::Pausar(true);
    voltarJogo= new BotaoEntidade(Vector2f(3.5,-1.5),0.3,"Voltar ao Jogo",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPause::VoltarJogo,this),nullptr);
    voltarMenu= new BotaoEntidade(Vector2f(3.5,-2.8),0.3,"Voltar ao Menu",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPause::VoltarMenu,this),nullptr);
    salvar= new BotaoEntidade(Vector2f(3.5,-4.1),0.3,"Salvar",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPause::Salvar,this),nullptr);
    
    entidades.Adicionar(voltarJogo);
    entidades.Adicionar(voltarMenu);
    entidades.Adicionar(salvar);
    

}
void MenuPause::VoltarJogo()
{
    Jogo::MenuAtual(nullptr);
    Tempo::Pausar(false);
}
void MenuPause::VoltarMenu()
{
    Jogo::MenuAtual(new MenuPrincipal());
    GerenciadorCenas::ProximaCena(-1);
}
void MenuPause::Salvar()
{
    cout<<"Salvar\n";
}
