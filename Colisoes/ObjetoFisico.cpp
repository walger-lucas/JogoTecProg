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
    Colisor& ObjetoFisico::getColisor()
    {
        return colisor;
    }
    void ObjetoFisico::setColidivel(const bool col)
    {
        colidivel = col;
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
    
}