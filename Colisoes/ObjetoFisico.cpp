#include"ObjetoFisico.h"
#include"CorpoRigido.h"
using namespace std;
using namespace sf;
using namespace Componentes;
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
    //refazer
    void ObjetoFisico::Resolver(ObjetoFisico& obj1,ObjetoFisico& obj2)
    {
        if(!obj1.getAtivo() ||!obj2.getAtivo() || (!obj1.getCinematico()&&!obj2.getCinematico()))//os dois nao cinematicos
            return;
        
        Colisor& col1 = obj1.getColisor();
        Colisor& col2 = obj2.getColisor();
        if(Colisor::Colide(col1,col2))
        {
            
            //avisa sobre a colisao aos dois obj
            obj1.Avisar(obj2);
            obj2.Avisar(obj1);
            if(!obj1.getColidivel() || !obj2.getColidivel())//qualquer um nao colidivel
                return;
            Vector2f intersec = Colisor::Interseccao(col1,col2);
            Vector2f vel=obj2.getVel()-obj1.getVel();//encontra a velocidade do obj2 no referencial do obj1
            Vector2f tempo;
            tempo.x= (vel.x*intersec.x<=0)? numeric_limits<float>::max(): abs(intersec.x/vel.x);
            tempo.y= (vel.y*intersec.y<=0)? numeric_limits<float>::max(): abs(intersec.y/vel.y);

            Vector2f mov1(0,0),mov2(0,0);
            float massaTotal=obj1.getMassa()+obj2.getMassa();
            if(tempo.x<tempo.y)
            {
                mov1.x= intersec.x*(obj2.getMassa()/massaTotal);
                mov2.x= -intersec.x*(obj1.getMassa()/massaTotal);    

            }
            else if(tempo.x>tempo.y)
            {
                mov1.y= intersec.y*obj2.getMassa()/massaTotal;
                mov2.y= -intersec.y*obj1.getMassa()/massaTotal; 

            }
            else
            {
                mov1.y= intersec.y*obj2.getMassa()/massaTotal;
                mov2.y= -intersec.y*obj1.getMassa()/massaTotal;
                mov1.x= intersec.x*(obj2.getMassa()/massaTotal);
                mov2.x= -intersec.x*(obj1.getMassa()/massaTotal);    
            }
            if(!obj1.getCinematico())
            {
                col2.Mover(mov2-mov1);
            }
            else if(!obj2.getCinematico())
            {
                col1.Mover(mov1-mov2);
            }
            else
            {
                col1.Mover(mov1);
                col2.Mover(mov2);
            }
            //atualiza tempo do primeiro obj
            if(tempo.x>obj1.tempoMaiorCol.x)
                obj1.tempoMaiorCol.x= tempo.x;
            if(tempo.y>obj1.tempoMaiorCol.y)
                obj1.tempoMaiorCol.y= tempo.y;
            //atualiza tempo do segundo obj
            if(tempo.x>obj2.tempoMaiorCol.x)
                obj2.tempoMaiorCol.x= tempo.x;
            if(tempo.y>obj2.tempoMaiorCol.y)
                obj2.tempoMaiorCol.y= tempo.y;
        }
      
    }
    void ObjetoFisico::Avisar(ObjetoFisico& obj)
    {
        if(corpo!=nullptr)
        {
            corpo->AvisarEscuta(&obj);
        }
    }
    void ObjetoFisico::Atualizar()
    {
        if(tempoMaiorCol !=Vector2f(0,0))
        {
            if(tempoMaiorCol.x<tempoMaiorCol.y)
                velocidade.x=0;
            else
                velocidade.y=0;
        }
        tempoMaiorCol = Vector2f(0,0);
    }
    
}