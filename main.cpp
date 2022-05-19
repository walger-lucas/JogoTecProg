#include"Entidade.h"
#include"Componentes/Posicao.h"
#include"Jogador.h"
#include"commons.h"
#include"ImgSprite.h"
#include"ImgTexto.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisoes.h"
#include"GerenciadorInputs.h"
using namespace Graficos;
using namespace sf;
using namespace std;
int main()
{
        Vector2f posc(0,-6);
    Vector2f dimc(10,1);
        ObjetoFisico* chao= new ObjetoFisico(&posc,&dimc,nullptr,true,false);
    GerenciadorColisoes::AddObjeto(chao);
    Jogador* j= new Jogador("Roger","cubo.png",false);
    j->Iniciar();
    Posicao *p = j->getComponente<Posicao>();
    p->setPos(Vector2f(3,-2));
    Vida *v = j->getComponente<Vida>();
    cout<<p->getX()<<endl;
    cout<<v->getVida()<<endl;
    v->machucar(15);
    cout<<v->getVida()<<endl;
    Jogador* k = new Jogador("Elis","hi.png",false);
    k->Iniciar();
    
    
    VideoMode vM(5000,500);
    RenderWindow rw(vM,"HeyListen",Style::Titlebar | Style::Close |Style::Resize);
    rw.setFramerateLimit(20);
    Vector2f pos3(3,-3);
    ImgTexto* txt= new ImgTexto(&pos3,0.2);
    txt->setTexto("Hola que\nTal");
    Font f;
    f.loadFromFile("ARIAL.TTF");
    txt->setFont(f);
    
    Gerenciadores::GerenciadorGrafico ger(&rw);
    GerenciadorColisoes gerC = GerenciadorColisoes();
    GerenciadorInputs gerI = GerenciadorInputs();
    gerI.setWindowAtual(&rw);
    

    Posicao* posC= k->getComponente<Posicao>();
    posC->setPos(Vector2f(3.1,-5));
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

    }
    delete j;
    delete k;
    

}