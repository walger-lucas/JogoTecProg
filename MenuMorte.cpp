#include "MenuMorte.h"
#include "MenuNovoJogo.h"
#include "MenuSalvar.h"
#include "MenuPrincipal.h"
#include "Tempo.h"
#include "Menu.h"
#include "Jogo.h"

MenuMorte::~MenuMorte()
{
    if(textoGameOver)
        textoGameOver->Destruir();
    if(voltarMenu)
        voltarMenu->Destruir();
}
void MenuMorte::Iniciar()
{
    Tempo::Pausar(true);
    voltarMenu= new BotaoEntidade(Vector2f(3.5,-2.8),0.3,"Voltar ao Menu",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuMorte::VoltarMenu,this),nullptr);
    pos = Vector2f(1.5,-1.5);
    textoGameOver = new ImgTexto(&pos,0.5);
    guest3D.loadFromFile("Arquivos/Fontes/Guest3D.ttf");
    textoGameOver->setFont(guest3D);
    textoGameOver->setTexto("Fim de Jogo!");
    GerenciadorGrafico::addUI(textoGameOver,1);
    entidades.Adicionar(voltarMenu);
}

void MenuMorte::VoltarMenu()
{
    Jogo::MenuAtual(new MenuPrincipal());
    GerenciadorCenas::ProximaCena(-1);
}