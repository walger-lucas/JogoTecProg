#include "MenuNovoJogo.h"
#include "Cena.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPrincipal.h"

MenuNovoJogo::MenuNovoJogo()
:Menu(),umJog(nullptr), doisJog(nullptr),cena1(nullptr),cena2(nullptr),comecar(nullptr),voltar(nullptr)
{
    botaoApertado.loadFromFile("Arquivos/Imagens/buttonA.png");
    botaoDesapertado.loadFromFile("Arquivos/Imagens/buttonB.png");
}
MenuNovoJogo::~MenuNovoJogo()
{
    if(doisJog)
        doisJog->Destruir();
    if(umJog)
        umJog->Destruir();
    if(cena1)
        cena1->Destruir();
    if(cena2)
        cena2->Destruir();
    if(voltar)
        voltar->Destruir();
    if(comecar)
        comecar->Destruir();
}
void MenuNovoJogo::Iniciar()
{
    umJog = new BotaoEntidade(Vector2f(1.5,-1.4),0.3,"Um Jogador",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::UmJogador,this),nullptr);
    doisJog = new BotaoEntidade(Vector2f(4.8,-1.4),0.3,"Dois Jogadores",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::DoisJogadores,this),nullptr);
    cena1 = new BotaoEntidade(Vector2f(1.5,-2.8),0.3,"Primeira Fase",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::Cena1,this),nullptr);
    cena2 = new BotaoEntidade(Vector2f(4.8,-2.8),0.3,"Segunda Fase",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::Cena2,this),nullptr);
    comecar = new BotaoEntidade(Vector2f(3.0,-4),0.3,"Iniciar Jogo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::Comecar,this),nullptr);
    voltar= new BotaoEntidade(Vector2f(0.2,-0.2),0.3,"Voltar",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuNovoJogo::Voltar,this),nullptr);
    
    entidades.Adicionar(umJog);
    entidades.Adicionar(doisJog);
    entidades.Adicionar(cena1);
    entidades.Adicionar(cena2);
    entidades.Adicionar(comecar);
    entidades.Adicionar(voltar);

}
void MenuNovoJogo::Voltar()
{
    Jogo::MenuAtual(new MenuPrincipal());
}
void MenuNovoJogo::UmJogador()
{
    umJog->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);
    doisJog->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
    Jogador::setDoisJogadores(false);
}
void MenuNovoJogo::DoisJogadores()
{
    doisJog->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);
    umJog->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
    Jogador::setDoisJogadores(true);
}
void MenuNovoJogo::Cena1()
{
    cena1->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);
    cena2->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
    cenaComecar=0;
}
void MenuNovoJogo::Cena2()
{
    cena2->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);
    cena1->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
    cenaComecar=1;
}
void MenuNovoJogo::Comecar()
{
    GerenciadorCenas::ProximaCena(cenaComecar);
    Tempo::Pausar(false);
    Jogador::zerarPontos();
    Jogador::resetarVidas();
    Jogo::MenuAtual(nullptr);
}
void MenuNovoJogo::Atualizar()
{

}

