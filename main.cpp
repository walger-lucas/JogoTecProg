#include"Entidade.h"
#include"Componentes/Posicao.h"
#include"Jogador.h"
#include"commons.h"
#include"ImgSprite.h"
#include"ImgTexto.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorColisoes.h"
using namespace Graficos;
using namespace sf;
using namespace std;
int main()
{
    
    Jogador* j= new Jogador("Roger","cubo.png",false);
    j->Iniciar();
    Posicao *p = j->getComponente<Posicao>();
    p->setPos(Vector2f(3,-2));
    Vida *v = j->getComponente<Vida>();
    cout<<p->getX()<<endl;
    cout<<v->getVida()<<endl;
    v->machucar(15);
    cout<<v->getVida()<<endl;
    Jogador* k = new Jogador("Elis","car.png",false);
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
    Vector2f posc(0,-6);
    Vector2f dimc(10,1);
    Posicao* posC= k->getComponente<Posicao>();
    posC->setPos(Vector2f(3.1,-5));
    ObjetoFisico* chao= new ObjetoFisico(&posc,&dimc,nullptr,true,false);
    gerC.AddObjeto(chao);
    
    
   // ger.cam.setDim(Vector2f(10,10));
    Gerenciadores::GerenciadorGrafico::addUI(txt,2);
    Gerenciadores::GerenciadorGrafico::setCorBorda(Color::Black);
    rw.setFramerateLimit(80);
    //ger.cam.Centralizar(img->getCentro());
    CorpoRigido* cp = j->getComponente<CorpoRigido>();
    Event ev;
    while (rw.isOpen())
    {
        while(rw.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                rw.close();
                break;
            case Event::Resized:
            {
                FloatRect visibleArea(0, 0, ev.size.width, ev.size.height);
                rw.setView(sf::View(visibleArea));
                break;
            }
            case Event::KeyPressed:
            {
                if(Keyboard::isKeyPressed(Keyboard::Key::Left))
                    ger.cam.Mover(Vector2f(-1,0));
                else if(Keyboard::isKeyPressed(Keyboard::Key::Right))
                    ger.cam.Mover(Vector2f(1,0));
                else if(Keyboard::isKeyPressed(Keyboard::Key::Up))
                    ger.cam.Mover(Vector2f(0,1));
                else if(Keyboard::isKeyPressed(Keyboard::Key::Down))
                    ger.cam.Mover(Vector2f(0,-1));
                if(Keyboard::isKeyPressed(Keyboard::Key::A)) 
                       cp->setVelocidade(Vector2f(-1.5,cp->getVelocidade().y));
                if(Keyboard::isKeyPressed(Keyboard::Key::D)) 
                       cp->setVelocidade(Vector2f(+1.5,cp->getVelocidade().y));
                if(Keyboard::isKeyPressed(Keyboard::Key::Space)) 
                       cp->setVelocidade(cp->getVelocidade()+Vector2f(0,2));
                if(Keyboard::isKeyPressed(Keyboard::Key::Y))
                        cp->setVelocidade(Vector2f(0,0));       
                break;
            }
            default:
                break;
            }
            
        }
        ger.Render();
        j->AtualizarFixo();
        gerC.ResolverColisoes();

    }
    delete j;
    delete k;
    

}