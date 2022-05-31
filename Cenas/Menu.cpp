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
}