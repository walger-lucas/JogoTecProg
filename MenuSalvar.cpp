#include "MenuSalvar.h"
#include "Cena.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPause.h"
#include "Salvador.h"

namespace Menus
{
    MenuSalvar::~MenuSalvar()
    {
        if(salvar)
            salvar->Destruir();
        if(nomeB)
            nomeB->Destruir();
        for(int i =0;i<5;i++)
        {
            if(saves[i])
                saves[i]->Destruir();
        }
        
    }
    void MenuSalvar::Iniciar()
    {
        nomeB = new BotaoEntidade(Vector2f(3.5,-0.5),0.3,"Escreva seu Nome",Vector2f(-30,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Nome,this),nullptr);
        salvar = new BotaoEntidade(Vector2f(3.0,-5.9),0.3,"Salvar Jogo",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Salvar,this),nullptr);
        voltar= new BotaoEntidade(Vector2f(0.2,-0.2),0.3,"Voltar",Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Voltar,this),nullptr);
        
        saves[0] = new BotaoEntidade(Vector2f(1.5,-2),0.3,Salvador::salvador->getNome(0),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Save0,this),nullptr);
        saves[1] = new BotaoEntidade(Vector2f(4.8,-2),0.3,Salvador::salvador->getNome(1),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Save1,this),nullptr);
        saves[2] = new BotaoEntidade(Vector2f(1.5,-3.4),0.3,Salvador::salvador->getNome(2),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Save2,this),nullptr);
        saves[3] = new BotaoEntidade(Vector2f(4.8,-3.4),0.3,Salvador::salvador->getNome(3),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Save3,this),nullptr);
        saves[4] = new BotaoEntidade(Vector2f(3,-4.8),0.3,Salvador::salvador->getNome(4),Vector2f(-50,-30),"buttonB.png","ARIAL.TTF",std::bind(&MenuSalvar::Save4,this),nullptr);
        
        
        entidades.Adicionar(nomeB);
        entidades.Adicionar(salvar);
        entidades.Adicionar(voltar);
        for(int i =0;i<5;i++)
        {
            entidades.Adicionar(saves[i]);
        }

    }
    void MenuSalvar::Voltar()
    {
        Jogo::MenuAtual(new MenuPause());
    }
    void MenuSalvar::Save0()
    {   
        Save(0);
    }
    void MenuSalvar::Save1()
    {   
        Save(1);
    }
    void MenuSalvar::Save2()
    {   
        Save(2);
    }
    void MenuSalvar::Save3()
    {   
        Save(3);
    }
    void MenuSalvar::Save4()
    {
        Save(4);
    }
    void MenuSalvar::Save(int atual)
    {
        if(atual>=0&&atual<5)
        {
            if(save>=0&&save<5)
                saves[save]->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoDesapertado);
            saves[atual]->getComponente<GraficoSprite>()->getSprite()->setTextura(botaoApertado);

            save=atual;
        }
    }
    void MenuSalvar::Salvar()
    {

        if(save>=0 &&save<5)
        {
            int savesSalvos=Salvador::salvador->getSavesSalvos();
            if(savesSalvos<save&&savesSalvos<5)
                save=savesSalvos;
            Salvador::salvador->salvarNovoJogo(save,nome);
            Jogo::MenuAtual(new MenuSalvar());
        }
    }
    void MenuSalvar::Nome()
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


    void MenuSalvar::Atualizar()
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
}