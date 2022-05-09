#include"Entidade.h"
#include"Componentes/Posicao.h"
#include"Jogador.h"
#include"commons.h"
#include"ImgSprite.h"
#include"GerenciadorGrafico.h"
using namespace Graficos;
using namespace sf;
using namespace std;
int main()
{
    
    Jogador* j= new Jogador("Roger","cubo.png",false);
    j->Carregar();
    j->Iniciar();
    Posicao *p = j->getComponente<Posicao>();
    p->setPos(Vector2f(3,-2));
    Vida *v = j->getComponente<Vida>();
    cout<<p->getX()<<endl;
    cout<<v->getVida()<<endl;
    v->machucar(15);
    cout<<v->getVida()<<endl;
    Jogador* k = new Jogador("Elis","car.png",true);
    k->Carregar();
    k->Iniciar();
    
    
    VideoMode vM(5000,500);
    RenderWindow rw(vM,"HeyListen",Style::Titlebar | Style::Close |Style::Resize);
    rw.setFramerateLimit(20);
    

    Gerenciadores::GerenciadorGrafico ger(&rw);
   // ger.cam.setDim(Vector2f(10,10));
    Gerenciadores::GerenciadorGrafico::setCorBorda(Color::Blue);
    //ger.cam.Centralizar(img->getCentro());
    
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
                
                break;
            }
            default:
                break;
            }
            
        }
        ger.Render();

    }
    delete j;
    delete k;
    

}