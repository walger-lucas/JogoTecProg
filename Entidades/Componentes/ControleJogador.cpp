#include "ControleJogador.h"
#include "Entidade.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "commons.h"
#include "Tempo.h"

using namespace sf;
namespace Componentes
{
    void ControleJogador::Iniciar()
    {
        cR = getEntidade()->getComponente<CorpoRigido>();
        posicao=getEntidade()->getComponente<Posicao>();
        vd=getEntidade()->getComponente<Vida>();
    }
    void ControleJogador::setControles(Keyboard::Key up,Keyboard::Key down,Keyboard::Key left,Keyboard::Key right)
    {
        this->up=up;
        this->down=down;
        this->right = right;
        this->left = left;
    }
    void ControleJogador::TestarChao()
    {
        list<ObjetoFisico*> l = Gerenciadores::GerenciadorColisoes::EncontraColisao(cR->getCentro()+distanciaChao);
        for(ObjetoFisico* ob : l)
        {
            CorpoRigido* cp =ob->getCorpoRigido();
            if(cp!=nullptr&& cp->getEntidade()->temTag(Entidades::TAG_GROUND))
            {
                isGrounded=true;
                return;
            }
        }
        isGrounded=false;
    }
    float lerp(float a,float b,float f)
    {
        return a + (b-a)*f;
    }
    void ControleJogador::Atualizar()
    {
        if(!vd->Vivo())
            getEntidade()->Destruir();
        //Provisorio
        TestarChao();
        
        if(Keyboard::isKeyPressed(left))
        {
            cR->setVelocidade(Vector2f(-4.0,cR->getVelocidade().y));
        } 
        else if(Keyboard::isKeyPressed(right))
        {
            cR->setVelocidade(Vector2f(4.0,cR->getVelocidade().y));
        }
        else
        {
            cR->setVelocidade(Vector2f(0,cR->getVelocidade().y));
        }

        if(Keyboard::isKeyPressed(up))
        {
            if(isGrounded)
                cR->setVelocidade(Vector2f(cR->getVelocidade().x,5.5));
            else if(cR->getVelocidade().y>0)
                cR->setVelocidade(cR->getVelocidade()+Vector2f(0,0.5*Gerenciadores::GerenciadorColisoes::gravidade*Configs::Tempo::getDeltaTempo()));
        }
        else if(Keyboard::isKeyPressed(down))
        {
         cR->setVelocidade(cR->getVelocidade()+Vector2f(0,-Gerenciadores::GerenciadorColisoes::gravidade*Configs::Tempo::getDeltaTempo()));   
        }
    }
    void ControleJogador::AtualizarFixo()
    {
        float x =lerp(Gerenciadores::GerenciadorGrafico::cam.getCentro().x,cR->getCentro().x,2*Configs::Tempo::getDeltaTempoFixo());
        Gerenciadores::GerenciadorGrafico::cam.setPos(Vector2f(x-Gerenciadores::GerenciadorGrafico::cam.getDim().x/2,Gerenciadores::GerenciadorGrafico::cam.getPos().y));
    }
    ControleJogador::ControleJogador()
    : Componente(),cR(nullptr),posicao(nullptr), isGrounded(false),distanciaChao(0,-0.51)
    {}

    void ControleJogador::Colidiu(ObjetoFisico* obj)
    {

    }
}