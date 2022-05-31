#include "MenuPrincipal.h"
#include "MenuNovoJogo.h"
#include "Menu.h"
#include "Jogo.h"

MenuPrincipal::~MenuPrincipal()
{
    if(nvJogo)
        nvJogo->Destruir();
    if(carJogo)
        carJogo->Destruir();
    if(sair)
        sair->Destruir();
    if(leaderBoard)
        leaderBoard->Destruir();
}
void MenuPrincipal::Iniciar()
{
    nvJ=false;
    nvJogo= new BotaoEntidade(Vector2f(3.5,-0.2),0.3,"Novo Jogo",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPrincipal::NovoJogo,this),nullptr);
    carJogo= new BotaoEntidade(Vector2f(3.5,-1.5),0.3,"Carregar Jogo",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPrincipal::CarregarOutroJogo,this),nullptr);
    sair= new BotaoEntidade(Vector2f(3.5,-4.1),0.3,"Sair",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPrincipal::Sair,this),nullptr);
    leaderBoard =  new BotaoEntidade(Vector2f(3.5,-2.8),0.3,"Leader Board",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&MenuPrincipal::LeaderBoard,this),nullptr);
    entidades.Adicionar(nvJogo);
    entidades.Adicionar(carJogo);
    entidades.Adicionar(sair);
    entidades.Adicionar(leaderBoard);
    

}
void MenuPrincipal::NovoJogo()
{
    Jogo::MenuAtual(new MenuNovoJogo());
}
void MenuPrincipal::CarregarOutroJogo()
{
    cout<<"Carregar\n";
}
void MenuPrincipal::LeaderBoard()
{
    cout<<"LeaderBoard\n";
}
void MenuPrincipal::Sair()
{
    GerenciadorInputs::FinalizarJogo();
}

