#include"Colisor.h"
#include"commons.h"

using namespace sf;
using namespace std;
namespace Colisoes
{
    const Vector2f Colisor::getPos() const
    {
        if(dimensao==nullptr)
            return Vector2f(0,0);
        return *posicao;
    }
    const Vector2f Colisor::getDim() const
    {
        if(dimensao==nullptr)
            return Vector2f(0,0);
        return *dimensao;
    }
    const Vector2f Colisor::getCentro() const
    {
        return Vector2f(this->getPos().x+this->getDim().x*0.5,this->getPos().y-this->getDim().y*0.5);
    }
    void Colisor::setPos(const Vector2f pos){
        if(posicao!=nullptr)
            *posicao=pos;
    }
    void Colisor::setDim(const Vector2f dim){
        if(dimensao!=nullptr)
            *dimensao=dim;
    }
    void Colisor::setCentro(const Vector2f pos){
        *posicao= Vector2f(pos.x-dimensao->x*0.5,pos.y+dimensao->y*0.5);
    }
    void Colisor::Mover(const Vector2f movimento)
    {
        if(posicao!= nullptr)
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
        float y1,y2,y3,y4;
        y1= pos1.y-pos2.y;
        y2 = pos1.y-(pos2.y-dim2.y);
        y3= pos1.y-dim1.y - pos2.y;
        y4 =pos1.y-dim1.y - (pos2.y-dim2.y);
        
        if(fabs(y1)<fabs(y2)&&fabs(y1)<fabs(y3) && fabs(y1)<fabs(y4))
        {
            intersection.y=y1;
        }
        else if(fabs(y2)<fabs(y3)&&fabs(y2)<fabs(y4))
        {
            intersection.y=y2;
        }
        else if(fabs(y3)<fabs(y4))
        {
            intersection.y=y3;
        }
        else
        {
            intersection.y =y4;
        }
        //std::cout<< y1<<" "<< " "<<y2<<" "<< y3<<" "<< y4<<std::endl<<intersection.y<<std::endl;
        
        float x1,x2,x3,x4;
        x1= pos1.x-pos2.x;
        x2 = pos1.x-(pos2.x+dim2.x);
        x3= pos1.x+dim1.x - pos2.x;
        x4 =pos1.x+dim1.x - (pos2.x+dim2.x);
        if(fabs(x1)<fabs(x2)&&fabs(x1)<fabs(x3) && fabs(x1)<fabs(x4))
        {
            intersection.x=x1;
        }
        else if(fabs(x2)<fabs(x3)&&fabs(x2)<fabs(x4))
        {
            intersection.x=x2;
        }
        else if(fabs(x3)<fabs(x4))
        {
            intersection.x=x3;
        }
        else
        {
            intersection.x =x4;
        }
        //std::cout<< x1<<" "<< " "<<x2<<" "<< x3<<" "<< x4<<std::endl<<intersection.x<<endl;
        if((pos2.y<pos1.y&&pos2.y-dim2.y>pos1.y-dim1.y)
        ||(pos1.y<pos2.y&&pos1.y-dim1.y>pos2.y-dim2.y))
            intersection.y=0;
        if((pos2.x>pos1.x && pos2.x+dim2.x< pos1.x+dim1.x)
        ||(pos1.x>pos2.x && pos1.x+dim1.x< pos2.x+dim2.x))
            intersection.x =0;

        return intersection;
    }
}   
