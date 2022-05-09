#include"Camera.h"
#include"commons.h"
using namespace sf;
using namespace Colisoes;
namespace Graficos{
    
    float Camera::pixPorUnidade(30.0);
    
    void Camera::setPPU(const float ppu)
    {
        pixPorUnidade = ppu;
    }
    const float Camera::getPPU()
    {
        return pixPorUnidade;
    }
    const Vector2f Camera::getPos() const
    {
        return posicao;
    }
    const Vector2f Camera::getDim() const
    {
        return dimensao;
    }
    const Vector2f Camera::getCentro() const
    {
        return Vector2f(posicao.x+dimensao.x*0.5,
            posicao.y-dimensao.y*0.5);
    }
    void Camera::setPos(const Vector2f pos)
    {
        posicao = pos;
    }
    void Camera::setDim(const Vector2f dim)
    {
        dimensao = dim;
    }
    void Camera::Mover(const Vector2f movimento)
    {
        posicao+= movimento;
    }
    void Camera::Centralizar(const Vector2f pos)
    {
        posicao = Vector2f(pos.x-dimensao.x*0.5,
            pos.y+dimensao.y*0.5);
    }
    const bool Camera::BoxDentro(const Colisor& col) const
    {
        Vector2f dim = dimensao;
        Vector2f pos = getPos();
        Colisor cam(&pos,&dim);//cria colisor com dimensoes da camera
        return Colisor::Colide(cam,col);//ve se colide colisor colide com camera
    }
    const bool Camera::BoxDentro(const Vector2f& pnt) const
    {
        Vector2f dim = dimensao;
        Vector2f pos = getPos();
        Colisor cam(&pos,&dim);//cria colisor com dimensoes da camera
        return Colisor::Colide(cam,pnt);//ve se colide colisor colide com camera
    }
    const Vector2f Camera::PosicaoVisCamera(const Vector2f pos) const
    {
        Vector2f vec =(pos-posicao)*pixPorUnidade;
        vec.y *=-1;
        return vec;
    }
    const Vector2f Camera::PosicaoVisGlobal(const Vector2f pos) const
    {
        Vector2f vec = (pos)*(1/pixPorUnidade);
        vec.y*=-1;
        vec+= posicao;
        return (vec);
    }
    const Vector2f Camera::PosUiTela(const Vector2f pos) const
    {
        Vector2f vec = (pos)*(pixPorUnidade);
        vec.y*=-1;
        return (vec);
    }
    const Vector2f Camera::PosTelaUi(const Vector2f pos) const
    {
        Vector2f vec = (pos)*(1/pixPorUnidade);
        vec.y*=-1;
        return (vec);
    }
}
