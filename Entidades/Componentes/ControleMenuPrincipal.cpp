#include "ControleMenuPrincipal.h"
namespace Componentes
{
    ControleMenuPrincipal::~ControleMenuPrincipal()
    {
        if(nvJogo)
            nvJogo->Destruir();
        if(carJogo)
            carJogo->Destruir();
        if(sair)
            sair->Destruir();
    }
    void ControleMenuPrincipal::Iniciar()
    {
        nvJ=false;
        nvJogo= new BotaoEntidade(Vector2f(3.5,-0.2),0.3,"Novo Jogo",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&ControleMenuPrincipal::NovoJogo,this),nullptr);
        carJogo= new BotaoEntidade(Vector2f(3.5,-1.5),0.3,"Carregar Jogo",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&ControleMenuPrincipal::CarregarOutroJogo,this),nullptr);
        sair= new BotaoEntidade(Vector2f(3.5,-4.1),0.3,"Sair",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&ControleMenuPrincipal::Sair,this),nullptr);
        leaderBoard =  new BotaoEntidade(Vector2f(3.5,-2.8),0.3,"Leader Board",Vector2f(-50,-30),"button0.png","ARIAL.TTF",std::bind(&ControleMenuPrincipal::LeaderBoard,this),nullptr);
        
        getEntidade()->getCena()->AdicionarEntidade(nvJogo);
        getEntidade()->getCena()->AdicionarEntidade(leaderBoard);
        getEntidade()->getCena()->AdicionarEntidade(sair);
        getEntidade()->getCena()->AdicionarEntidade(carJogo);

    }
    void ControleMenuPrincipal::NovoJogo()
    {
        cout<<"new Game\n";
        nvJ=true;
    }
    void ControleMenuPrincipal::CarregarOutroJogo()
    {
        cout<<"Carregar\n";
    }
    void ControleMenuPrincipal::LeaderBoard()
    {
        cout<<"LeaderBoard\n";
    }
    void ControleMenuPrincipal::Sair()
    {
        GerenciadorInputs::FinalizarJogo();
    }
    void ControleMenuPrincipal::Atualizar()
    {
        if(nvJ)
        {
            getEntidade()->getCena()->MudarCena(1);
        }
            
        
    }
}