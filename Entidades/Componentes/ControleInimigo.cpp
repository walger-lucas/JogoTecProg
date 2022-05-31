#include "ControleInimigo.h"
#include "GerenciadorColisoes.h"
#include "Componente.h"
#include "IEscutaColisao.h"
#include "Jogador.h"
#include <random>
using namespace sf;
using namespace Entidades;
namespace Componentes
{

    void ControleInimigo::Iniciar()
    {
        pos = getEntidade()->getComponente<Posicao>();
        gS = getEntidade()->getComponente<GraficoSprite>();
        cR = getEntidade()->getComponente<CorpoRigido>();
        vida = getEntidade()->getComponente<Vida>();
        cR->addEscuta(this);
    }
    void ControleInimigo::TestarChao()
    {
        list<ObjetoFisico*> l = Gerenciadores::GerenciadorColisoes::EncontraColisao(cR->getCentro()+posBuscaChao);
        direitaChao=false;
        for(ObjetoFisico* ob : l)
        {
            CorpoRigido* cp =ob->getCorpoRigido();
            if(cp!=nullptr&& cp->getEntidade()->temTag(Entidades::TAG_GROUND))
            {
                direitaChao=true;
            }
        }
        Vector2f pos = posBuscaChao;
        pos.x*=-1;
        l=Gerenciadores::GerenciadorColisoes::EncontraColisao(cR->getCentro()+pos);
        esquerdaChao=false;
        for(ObjetoFisico* ob : l)
        {
            CorpoRigido* cp =ob->getCorpoRigido();
            if(cp!=nullptr&& cp->getEntidade()->temTag(Entidades::TAG_GROUND))
            {
                esquerdaChao=true;
            }
        }
        
    }
    void ControleInimigo::setModVelocidade(const float mod)
    {
        movimento.setModVelocidade(mod);
    }
    void ControleInimigo::setModPulo(const float mod)
    {
        movimento.setModPulo(mod);
    }

    ControleInimigo::ControleInimigo(Vector2f posChao,const float vel, const float pulo,const float rec)
    :Componente(),posBuscaChao(posChao),movimento(vel,pulo,true,rec)
    {
        indoDireita=std::rand()%2;
    }
    ControleInimigo::~ControleInimigo()
    {}
    bool ControleInimigo::objEmCima(ObjetoFisico* obj)
    {
            Colisor& col = obj->getColisor();
            return col.getPos().y-col.getDim().y>=pos->getY()-0.1;
    }
    bool ControleInimigo::objEmBaixo(ObjetoFisico* obj)
    {
        Colisor& col = obj->getColisor();
        return pos->getY()-cR->getDim().y>=col.getPos().y-0.1;
    }

}
