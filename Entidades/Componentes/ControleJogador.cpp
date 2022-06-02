#include "ControleJogador.h"
#include "Entidade.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "commons.h"
#include "Tempo.h"
#include "Jogador.h"
#include "Plataforma.h"

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
            if(cp!=nullptr&& (cp->getEntidade()->temTag(Plataforma::TAG_GROUND)||cp->getEntidade()->temTag(Entidades::Jogador::TAG_JOGADOR)))
            {
                isGrounded=true;
                return;
            }
        }
        isGrounded=false;
    }
    void ControleJogador::Atualizar()
    {
        movimento.RecuperarMods();
        if(!vd->Vivo())
            getEntidade()->Destruir();
        if(Keyboard::isKeyPressed(left))
        {
            cR->setVelocidade(Vector2f(-movimento.getVelocidade(),cR->getVelocidade().y));
        } 
        else if(Keyboard::isKeyPressed(right))
        {
            cR->setVelocidade(Vector2f(movimento.getVelocidade(),cR->getVelocidade().y));
        }
        else
        {
            cR->setVelocidade(Vector2f(0,cR->getVelocidade().y));
        }

        if(Keyboard::isKeyPressed(up))
        {
            if(isGrounded)
                cR->setVelocidade(Vector2f(cR->getVelocidade().x,movimento.getPulo()));
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
        TestarChao();
    }
    void ControleJogador::setModVelocidade(const float mod)
    {
        movimento.setModVelocidade(mod);
    }
    void ControleJogador::setModPulo(const float mod)
    {
        movimento.setModPulo(mod);
    }
    ControleJogador::ControleJogador()
    :Componente(),cR(nullptr),posicao(nullptr),movimento(4,5.5,true,0.9), isGrounded(false),distanciaChao(0,-0.51)
    {}

    void ControleJogador::Colidiu(ObjetoFisico* obj)
    {

    }
}