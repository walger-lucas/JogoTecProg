#include "MenuPlacar.h"
#include "Cena.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPrincipal.h"
#include "Lideranca.h"

MenuPlacar::~MenuPlacar()
{
    if(cima)
        cima->Destruir();
    if(baixo)
        baixo->Destruir();
    if(voltarMenu)
        voltarMenu->Destruir();
    if(placar)
        placar->Destruir();
}
void MenuPlacar::Iniciar()
{
    cima = new BotaoEntidade(Vector2f(6,-0.2),0.3,"Cima",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPlacar::Cima,this),nullptr);
    baixo = new BotaoEntidade(Vector2f(6,-1.8),0.3,"Baixo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPlacar::Baixo,this),nullptr);
    voltarMenu= new BotaoEntidade(Vector2f(0.2,-0.2),0.3,"Voltar",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuPlacar::VoltarMenu,this),nullptr);
    pos = Vector2f(1.5,-1.2);
    placar = new ImgTexto(&pos,0.25);
    arial.loadFromFile("Arquivos/Fontes/ARIAL.TTF");
    placar->setFont(arial);
    placar->setTexto(Lideranca::getInfo(0,15));
    GerenciadorGrafico::addUI(placar,1);
    entidades.Adicionar(baixo);
    entidades.Adicionar(cima);
    entidades.Adicionar(voltarMenu);

}
void MenuPlacar::VoltarMenu()
{
    Jogo::MenuAtual(new MenuPrincipal());
}
void MenuPlacar::Baixo()
{
    if(pagina<(Lideranca::numeroLideres()-1)/15)
        pagina++;
    placar->setTexto(Lideranca::getInfo(pagina*15,(pagina+1)*15));
}
void MenuPlacar::Cima()
{
    if(pagina>0)
        pagina--;
    placar->setTexto(Lideranca::getInfo(pagina*15,(pagina+1)*15));
}


