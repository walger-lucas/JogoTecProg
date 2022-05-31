#include "Menu.h"
#include "BotaoEntidade.h"
#include "GerenciadorInputs.h"
#include "EntidadeMenuPrincipal.h"
namespace Cenas
{
    void Menu::Carregar()
    {
        *this+= new EntidadeMenuPrincipal();
    }
    void Menu::novoJogo()
    {
        
        cout<<"new Game\n";
        MudarCena(0);
    }
    void Menu::CenaUm()
    {}
    void Menu::CenaDois()
    {}
    void Menu::UmJogador()
    {}
    void Menu::DoisJogadores()
    {}
    void Menu::carregarJogoAntigo()
    {
        cout<<"Jogo Antigo\n";
    }
    void Menu::leaderBoard()
    {}
    void Menu::sair()
    {
        GerenciadorInputs::FinalizarJogo();
    }
    void Menu::voltar()
    {}
}