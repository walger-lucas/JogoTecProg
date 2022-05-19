#include"GerenciadorInputs.h"
#include"GerenciadorGrafico.h"
#include"EventoBotao.h"
using namespace sf;
using namespace std;
namespace Gerenciadores
{
    RenderWindow* GerenciadorInputs::window(nullptr);
    list<EventoBotao*> GerenciadorInputs::botoes=list<EventoBotao*>();
    void GerenciadorInputs::PollEvents()
    {
        while(window->pollEvent(evento))
        {
            switch (evento.type)
            {
                case sf::Event::Closed: //Fecha janela quando botao de fechar apertado
                    window->close();
                    break;
                case Event::Resized: //reproporciona tamanho da janela.
                {
                    FloatRect visibleArea(0, 0, evento.size.width, evento.size.height);
                    window->setView(View(visibleArea));
                    break;
                }
                case Event::MouseButtonPressed:
                {
                    //tenta apertar botoes dando a posicao do mouse em UI na tela.
                    Vector2f posMouse = getMouseUIPos();
                    for(auto botao : botoes)
                    {
                        botao->Apertar(posMouse);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    void GerenciadorInputs::setWindowAtual(RenderWindow* rW)
    {
        window = rW;
    }
    const Vector2f GerenciadorInputs::getMouseGlobalPos()
    {
        Vector2i posI = Mouse::getPosition(*window);
        Vector2f posF(posI.x,posI.y);
        return GerenciadorGrafico::PosTelaParaGlobal(posF);
    }
    const Vector2f GerenciadorInputs::getMouseUIPos()
    {
        Vector2i posI = Mouse::getPosition(*window);
        Vector2f posF(posI.x,posI.y);
        return GerenciadorGrafico::PosTelaParaUi(posF);
    }
    //descobre se a pos do mouse global esta aparecendo na camera.
    const bool GerenciadorInputs::isMouseNaTela()
    {
        return GerenciadorGrafico::cam.BoxDentro(getMouseGlobalPos());
    }
    void GerenciadorInputs::addBotao(EventoBotao* botao)
    {
        botoes.push_back(botao);
    }
    void GerenciadorInputs::removeBotao(EventoBotao* botao)
    {
        botoes.remove(botao);
    }
}