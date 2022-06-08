#include "MenuCarregar.h"
#include "Cena.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPrincipal.h"
#include "Salvador.h"

namespace Menus
{
    MenuCarregar::~MenuCarregar()
    {
        if(carregar)
            carregar->Destruir();
        for(int i =0;i<5;i++)
        {
            if(saves[i])
                saves[i]->Destruir();
        }
        
    }
    void MenuCarregar::Iniciar()
    {
        carregar = new BotaoEntidade(Vector2f(6.0,-0.2),0.3,"Carregar Jogo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Carregar,this),nullptr);
        voltar= new BotaoEntidade(Vector2f(0.2,-0.2),0.3,"Voltar",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Voltar,this),nullptr);
        saves[0] = new BotaoEntidade(Vector2f(1.5,-2),0.3,Salvador::salvador->getNome(0),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Save0,this),nullptr);
        saves[1] = new BotaoEntidade(Vector2f(4.8,-2),0.3,Salvador::salvador->getNome(1),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Save1,this),nullptr);
        saves[2] = new BotaoEntidade(Vector2f(1.5,-3.4),0.3,Salvador::salvador->getNome(2),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Save2,this),nullptr);
        saves[3] = new BotaoEntidade(Vector2f(4.8,-3.4),0.3,Salvador::salvador->getNome(3),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Save3,this),nullptr);
        saves[4] = new BotaoEntidade(Vector2f(3,-4.8),0.3,Salvador::salvador->getNome(4),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuCarregar::Save4,this),nullptr);
        entidades.Adicionar(carregar);
        entidades.Adicionar(voltar);
        for(int i =0;i<5;i++)
        {
            entidades.Adicionar(saves[i]);
        }

    }
    void MenuCarregar::Voltar()
    {
        Jogo::MenuAtual(new MenuPrincipal());
    }
    void MenuCarregar::Save0()
    {   
        Save(0);
    }
    void MenuCarregar::Save1()
    {   
        Save(1);
    }
    void MenuCarregar::Save2()
    {   
        Save(2);
    }
    void MenuCarregar::Save3()
    {   
        Save(3);
    }
    void MenuCarregar::Save4()
    {
        Save(4);
    }
    void MenuCarregar::Save(int atual)
    {
        if(atual>=0&&atual<5)
        {
            if(save>=0&&save<5)
                saves[save]->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
            saves[atual]->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);

            save=atual;
        }
    }
    void MenuCarregar::Carregar()
    {

        if(save>=0 &&save<5&&Salvador::salvador->getSavesSalvos()>save)
        {
            Salvador::salvador->carregarSave(save);
            Jogo::MenuAtual(nullptr);
        }
    }
}