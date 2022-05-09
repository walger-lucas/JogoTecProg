#include"Colisor.h"

using namespace sf;
namespace Colisoes
{
    const Vector2f Colisor::getPos() const
    {
        return *posicao;
    }
    const Vector2f Colisor::getDim() const
    {
        return *dimensao;
    }
    const Vector2f Colisor::getCentro() const
    {
        return Vector2f(posicao->x+dimensao->x*0.5,posicao->y-dimensao->y*0.5);
    }
    void Colisor::setPos(const Vector2f pos){
        *posicao=pos;
    }
    void Colisor::setDim(const Vector2f dim){
        *dimensao=dim;
    }
    void Colisor::setCentro(const Vector2f pos){
        *posicao= Vector2f(pos.x-dimensao->x*0.5,pos.y+dimensao->y*0.5);
    }
    void Colisor::Mover(const Vector2f movimento)
    {
        *posicao+=movimento;
    }
    const bool Colisor::Colide(const Colisor& col1,const Colisor& col2)
    {
        Vector2f pos1 = col1.getPos(),pos2 = col2.getPos(),
            dim1 = col1.getDim(), dim2=col2.getDim();
        if(pos1.y<=pos2.y-dim2.y //tests if top of b1 is lower than bottom of b2
        || pos1.y-dim1.y >= pos2.y //tests if bottom of b1 is higher than top of b2
        || pos1.x + dim1.x <= pos2.x//tests if right of b1 is lower than left of b2
        ||pos1.x >= pos2.x+dim2.x )//tests if left of b1 is higher than b2 right side
        {
            return false; //will enter only if outside or int he limit of box, if so, return false
        }
        return true;
    }
    const bool Colisor::Colide(const Colisor& col,const Vector2f& ponto)
    {
        Vector2f pos = col.getPos(),dim = col.getDim();
        if(ponto.x <= pos.x //if left of box left side
        || ponto.x >= pos.x + dim.x //if right of box right side
        || ponto.y >= pos.y //if over box top
        || ponto.y<= pos.y-dim.y) //if under box bottom
        {
            return false; //if anywhere but inside the box
        }
        return true;
    }
    //vetor do movimento necessario para col1 sair de colisao com col2
    const Vector2f Colisor::Interseccao(const Colisor& col1,const Colisor& col2)
    {
        Vector2f intersection(0,0);
        Vector2f pos1 = col1.getPos(),pos2 = col2.getPos(),
            dim1 = col1.getDim(), dim2=col2.getDim();
        //if intersector intersects upside of box, take the y distance to stop intersection moving up
        //else if intersector intersects the downside, take the y distance to stop intersection moving down
        if(pos2.y>pos1.y - dim1.y && pos2.y<pos1.y)
        {
            intersection.y = pos2.y-(pos1.y - dim1.y);
        }
        if(pos2.y-dim2.y <pos1.y && pos2.y-dim2.y > pos1.y - dim1.y)
        {
            float result = pos2.y-dim2.y-pos1.y;
            if(intersection.y==0 || intersection.y > result)
                intersection.y = result;
        }

        //if intersector intersects leftside of box, take the x distance to stop intersection moving left
        //else if intersector intersects the right side, take the x distance to stop intersection moving right
        if(pos2.x > pos1.x && pos2.x< pos1.x+dim1.x)
        {
            intersection.x= pos2.x - (pos1.x+dim1.x);
        }
        if(pos2.x+dim2.x > pos1.x &&pos2.x+dim2.x <pos1.x+dim1.x)
        {
            //tests to see if has already found an intersection and picks the smallest if has already found one.
            float result = (pos2.x+dim2.x) - pos1.x;
            if(intersection.x==0 || -intersection.x> result)
                intersection.x=result;
        }
            
        return intersection;
    }
}   
