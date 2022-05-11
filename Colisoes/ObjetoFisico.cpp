#include"ObjetoFisico.h"
using namespace std;
using namespace sf;
namespace Colisoes{
    const bool ObjetoFisico::getColidivel() const
    {
        return colidivel;
    }
    const bool ObjetoFisico::getCinematico() const
    {
        return cinematico;
    }
    const bool ObjetoFisico::getAtivo() const
    {
        return ativo;
    }
    const bool ObjetoFisico::getDestruir() const
    {
        return destruir;
    }
    const Vector2f ObjetoFisico::getVel() const
    {
        return velocidade;
    }
    const float ObjetoFisico::getMassa() const
    {
        return massa;
    }
    Colisor& ObjetoFisico::getColisor()
    {
        return colisor;
    }
    void ObjetoFisico::setColidivel(const bool col)
    {
        colidivel = col;
    }
    void ObjetoFisico::setMassa(const float massa)
    {
        if(massa!=0)
            this->massa=massa;
    }
    void ObjetoFisico::setCinematico(const bool cine)
    {
        cinematico = cine;
    }
    void ObjetoFisico::setAtivo(const bool atv)
    {
        ativo = atv;
    }
    void ObjetoFisico::setVel(const Vector2f vel)
    {
        velocidade= vel;
    }
    void ObjetoFisico::addVel(const Vector2f vel)
    {
        velocidade= vel+ velocidade;
    }
    void ObjetoFisico::Destruir()
    {
        destruir = true;
    }
    const Vector2f ObjetoFisico::Resolver(ObjetoFisico& obj)
    {
        Colisor& col = obj.getColisor();
        if(cinematico&& obj.getColidivel() && Colisor::Colide(colisor,col))
        {
            if(colidivel)
            {
                Vector2f interseccao = Colisor::Interseccao(colisor,col);
                Vector2f velsoma= (obj.getCinematico()) ? obj.getVel()+velocidade:velocidade;
                if(velsoma==Vector2f(0,0))
                    return Vector2f(0,0);
                Vector2f tempoInter(abs(interseccao.x/velsoma.x),abs(interseccao.y/velsoma.y));
                Vector2f mover(0,0);
                Vector2f moverObj(0,0);
                float massaT = massa+obj.getMassa();
                if(tempoInter.x>tempoInter.y)
                {
                    mover.x+=interseccao.x*obj.getMassa()/massaT;
                    moverObj.x-=interseccao.x*massa/massaT;
                }
                else
                {
                    mover.y+=interseccao.y*obj.getMassa()/massaT;
                    moverObj.y-=interseccao.y*massa/massaT;
                }
                if(obj.getCinematico())
                    col.Mover(moverObj);
                colisor.Mover(mover);
                return tempoInter;
            }
            return Vector2f(0,0);
        }
    }
}