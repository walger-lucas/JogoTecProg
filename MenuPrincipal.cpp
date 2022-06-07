#include "MenuPrincipal.h"
#include "MenuNovoJogo.h"
#include "MenuCarregar.h"
#include "Menu.h"
#include "Jogo.h"
#include "MenuPlacar.h"

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
    if(titulo)
        titulo->Destruir();
}
void MenuPrincipal::Iniciar()
{
    nvJ=false;
    nvJogo= new BotaoEntidade(Vector2f(3.5,-1.2),0.3,"Novo Jogo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPrincipal::NovoJogo,this),nullptr);
    carJogo= new BotaoEntidade(Vector2f(3.5,-2.5),0.3,"Carregar Jogo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPrincipal::CarregarOutroJogo,this),nullptr);
    sair= new BotaoEntidade(Vector2f(3.5,-5.1),0.3,"Sair",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPrincipal::Sair,this),nullptr);
    leaderBoard =  new BotaoEntidade(Vector2f(3.5,-3.8),0.3,"Leader Board",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPrincipal::LeaderBoard,this),nullptr);
    entidades.Adicionar(nvJogo);
    entidades.Adicionar(carJogo);
    entidades.Adicionar(sair);
    entidades.Adicionar(leaderBoard);
    pos = Vector2f(0.5,-0.2);
    titulo = new ImgTexto(&pos,0.4);
    guest3D.loadFromFile("Arquivos/Fontes/Guest3D.ttf");
    titulo->setFont(guest3D);
    titulo->setTexto("Cenouras em Combate");
    GerenciadorGrafico::addUI(titulo,1);
    

}
void MenuPrincipal::NovoJogo()
{
    Jogo::MenuAtual(new MenuNovoJogo());
}
void MenuPrincipal::CarregarOutroJogo()
{
    Jogo::MenuAtual(new MenuCarregar());
}
void MenuPrincipal::LeaderBoard()
{
    Jogo::MenuAtual(new MenuPlacar());
}
void MenuPrincipal::Sair()
{
    GerenciadorInputs::FinalizarJogo();
}

