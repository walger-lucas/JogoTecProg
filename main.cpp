#include"Entidade.h"
#include"Componentes/Posicao.h"
#include"Jogador.h"
#include"commons.h"
#include"ImgSprite.h"
#include"ImgTexto.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisoes.h"
#include"GerenciadorInputs.h"
#include"GerenciadorArquivos.h"
#include"EventoBotao.h"
#include "BotaoEntidade.h"
using namespace Graficos;
using namespace sf;
using namespace std;
void apt()
{
    cout<<"botao apertado\n";
}
void dapt()
{
    cout << "botao desapertado\n";
}
int main()
{
    GerenciadorArquivos::CarregarFonte("arial","ARIAL.TTF");
    GerenciadorArquivos::CarregarTextura("cubo","cubo.png");
    GerenciadorArquivos::CarregarTextura("button0","button0.png");
    GerenciadorArquivos::CarregarTextura("hi","hi.png");
    Vector2f posc(0,-6);
    Vector2f dimc(10,1);
    ObjetoFisico* chao= new ObjetoFisico(&posc,&dimc,nullptr,true,false);
    GerenciadorColisoes::AddObjeto(chao);
    Jogador* j= new Jogador("Roger","cubo",false);
    j->Iniciar();
    Posicao *p = j->getComponente<Posicao>();
    p->setPos(Vector2f(3,-2));
    Jogador* k = new Jogador("Elis","hi",false);
    k->Iniciar();
    /*EventoBotao bot(p->getPPos(),p->getPEsc());
    bot.setFuncApertar(apt);
    bot.setFuncDesapertar(dapt);*/
    BotaoEntidade* bot = new BotaoEntidade(Vector2f(1,-2),0.3,"Hola",Vector2f(-40,-25),"button0","arial",apt,dapt);
    bot->Iniciar();
    
    VideoMode vM(5000,500);
    RenderWindow rw(vM,"HeyListen",Style::Titlebar | Style::Close |Style::Resize);
    rw.setFramerateLimit(20);
    Vector2f pos3(3,-3);

    ImgTexto* txt= new ImgTexto(&pos3,0.2);
    txt->setTexto("Hola que\nTal");

    txt->setFont(*GerenciadorArquivos::getFonte("arial"));
    
    Gerenciadores::GerenciadorGrafico ger(&rw);
    GerenciadorColisoes gerC = GerenciadorColisoes();
    GerenciadorInputs gerI = GerenciadorInputs();
    gerI.setWindowAtual(&rw);
    

    Posicao* posC= k->getComponente<Posicao>();
    posC->setPos(Vector2f(3.1,20));
    Gerenciadores::GerenciadorGrafico::addUI(txt,2);
    Gerenciadores::GerenciadorGrafico::setCorBorda(Color::Black);
    rw.setFramerateLimit(80);
    CorpoRigido* cp = j->getComponente<CorpoRigido>();
    while (rw.isOpen())
    {
        gerI.PollEvents();
        ger.Render();
        j->AtualizarFixo();
        k->AtualizarFixo();
        gerC.ResolverColisoes();
        if(Keyboard::isKeyPressed(Keyboard::Key::Left))
        {
            cp->setVelocidade(Vector2f(-4.0,cp->getVelocidade().y));
        } 
        else if(Keyboard::isKeyPressed(Keyboard::Key::Right))
        {
            cp->setVelocidade(Vector2f(4.0,cp->getVelocidade().y));
        }
        else
        {
            cp->setVelocidade(Vector2f(0,cp->getVelocidade().y));
        }

        if(Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            cp->setVelocidade(Vector2f(cp->getVelocidade().x,2));
        }

    }
    delete j;
    delete k;
    delete bot;
    

}
