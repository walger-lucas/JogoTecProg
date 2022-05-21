#include "Posicao.h"
namespace Componentes{

    const float Posicao::getX() const
    {
        return posicao.x;
    }
    const float Posicao::getY() const
    {
        return posicao.y;
    }
    const float Posicao::getEscX() const
    {
        return escala.x;
    }
    const float Posicao::getEscY() const
    {
        return escala.y;
    }
    const Vector2f Posicao::getPos() const
    {
        return posicao;
    }
    void Posicao::setPos(const Vector2f pos)
    {
        posicao= pos;
    }
    const Vector2f Posicao::getEscala() const
    {
        return escala;
    }
    void Posicao::setEscala(const Vector2f esc)
    {
        escala= esc;
    }
    Vector2f* Posicao::getPPos()
    {
        return &posicao;
    }
    Vector2f* Posicao::getPEsc()
    {
        return &escala;
    }
}