#include"ImgSprite.h"
#include"GerenciadorGrafico.h"
using namespace Gerenciadores;
using namespace sf;
namespace Graficos{
    const Vector2f ImgSprite::getPos() const
    {
        return *posicao;
    }
    const Vector2f ImgSprite::getDim() const
    {
        return dimensao;
    }
    const Vector2f ImgSprite::getEscala() const
    {
        return *escala;
    }
    const Vector2f ImgSprite::getCentro() const
    {
        return Vector2f(posicao->x+0.5*dimensao.x*escala->x,posicao->y-0.5*dimensao.y*escala->y);
    }
    void ImgSprite::setTextura(const Texture& textura)
    {
        sprite.setTexture(textura);
        sprite.setTextureRect(IntRect(Vector2i(0,0),Vector2i(textura.getSize().x,textura.getSize().y)));
        setDim();
    }
    void ImgSprite::setDim(bool x)
    {
        float height =sprite.getTextureRect().height;
        float width = sprite.getTextureRect().width;
        if(x)
            dimensao= Vector2f(1,height/width);
        else
            dimensao= Vector2f(width/height,1);
    }
    void ImgSprite::setDim(Vector2f dim)
    {
        dimensao = dim;
    }
    void ImgSprite::setOrigin(const Vector2f pos)
    {
        sprite.setOrigin(pos);
    }
    //A Fazer: fazer funcao de local de camera para local de
    Drawable* ImgSprite::Desenhar()
    {
        Vector2f dimReal = Vector2f(dimensao.x*escala->x,dimensao.y*escala->y);
        Vector2f pos = *posicao+sprite.getOrigin()/GerenciadorGrafico::cam.getPPU();
        Colisor col(&pos,&dimReal);
        if(GerenciadorGrafico::cam.BoxDentro(col))
        {
            sprite.setPosition(GerenciadorGrafico::PosGlobalParaTela(*posicao));
            Vector2f dim = (GerenciadorGrafico::cam.getPPU())*(dimReal);
            IntRect rect = sprite.getTextureRect();
            sprite.setScale(dim.x/rect.width,dim.y/rect.height);
            return (static_cast<Drawable*>(&sprite));
        }
        return nullptr;


    }
    Drawable* ImgSprite::DesenharUI()
    {
        Vector2f dimReal = Vector2f(dimensao.x*escala->x,dimensao.y*escala->y);
        Vector2f pos = *posicao+sprite.getOrigin()/GerenciadorGrafico::cam.getPPU();
        Colisor col(&pos,&dimReal);
        sprite.setPosition(GerenciadorGrafico::PosUiParaTela(*posicao));
        Vector2f dim = GerenciadorGrafico::cam.getPPU()*dimReal;
        IntRect rect = sprite.getTextureRect();
        sprite.setScale(dim.x/rect.width,dim.y/rect.height);
        return (static_cast<Drawable*>(&sprite));
    }
}