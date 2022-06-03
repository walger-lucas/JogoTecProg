#include"CorpoRigido.h"
#include"Posicao.h"
#include"GerenciadorColisoes.h"
#include"ObjetoFisico.h"
#include"Tempo.h"
using namespace std;
using namespace sf;
using namespace Colisoes;
using namespace Gerenciadores;
namespace Componentes
{
    const Vector2f CorpoRigido::getVelocidade() const
    {
        return obj->getVel();
    }
    void CorpoRigido::setVelocidade(const Vector2f vel)
    {
        obj->setVel(vel);
    }
    const Vector2f CorpoRigido::getDim() const
    {
        return dimensao;
    }
    const Vector2f CorpoRigido::getCentro()
    {
        return obj->getColisor().getCentro();
    }
    void CorpoRigido::setDim(const Vector2f dim)
    {
        dimensao=dim;
    }

    const bool CorpoRigido::getGravidade() const
    {
        return gravidade;
    }
    void CorpoRigido::setGravidade(const bool grav)
    {
        gravidade = grav;
    }
    void CorpoRigido::setColidivel(const bool col)
    {
        obj->setColidivel(col);
    }
    void CorpoRigido::setCinematico(const bool cine)
    {
        obj->setCinematico(cine);
    }
    void CorpoRigido::addEscuta(IEscutaColisao* escuta)
    {
        if(escuta!= nullptr)
            escutas.push_back(escuta);
    }
    void CorpoRigido::AvisarEscuta(ObjetoFisico* obj)
    {
        for(auto escuta : escutas)
        {
            escuta->Colidiu(obj);
        }
    }
    void CorpoRigido::Iniciar()
    {
        Entidade* ent = getEntidade();
        if(ent!=nullptr)
        {
            Posicao* pos = ent->getComponente<Posicao>();
            obj = new ObjetoFisico(pos->getPPos(),&dimensao,this,colidivel,cinematico);
            GerenciadorColisoes::AddObjeto(obj);
        }
    }
    void CorpoRigido::setAtivado(bool atv)
    {
        Componente::setAtivado(atv);
        if(obj!=nullptr)
            obj->setAtivo(atv);
    }

    void CorpoRigido::AtualizarFixo()
    {
        if(gravidade)
        {
            obj->addVel(Vector2f(0,-GerenciadorColisoes::gravidade*Configs::Tempo::getDeltaTempoFixo()));
            //diminuicao gradativa da velocidade
            float atrito =-GerenciadorColisoes::gravidade*Configs::Tempo::getDeltaTempoFixo()/30.0;
            obj->addVel(atrito*getVelocidade());
        }
        //Tempo::getDeltaTempoFixo()
    }

}