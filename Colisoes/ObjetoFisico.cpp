#include "ObjetoFisico.h"
#include "CorpoRigido.h"
#include "GerenciadorColisoes.h"
#include "Tempo.h"
using namespace std;
using namespace sf;
using namespace Componentes;
using namespace Configs;

namespace Colisoes
{
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

    Colisor &ObjetoFisico::getColisor()
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
        velocidade = vel;
    }
    void ObjetoFisico::addVel(const Vector2f vel)
    {
        velocidade = vel + velocidade;
    }
    void ObjetoFisico::Destruir()
    {
        destruir = true;
    }
    // refazer
    void ObjetoFisico::Resolver(ObjetoFisico &obj1, ObjetoFisico &obj2)
    {
        if (!obj1.getAtivo() || !obj2.getAtivo() || (!obj1.getCinematico() && !obj2.getCinematico())) // os dois nao cinematicos
            return;

        Colisor &col1 = obj1.getColisor();
        Colisor &col2 = obj2.getColisor();
        if (Colisor::Colide(col1, col2))
        {

            if(!obj1.colidivel||!obj2.colidivel)
                return;
            Vector2f vel =obj2.velocidade-obj1.velocidade;
            
            Vector2f tempo;
            tempo.x= (vel.x==0)? numeric_limits<float>::max(): min((obj1.posAnterior.x+col1.getDim().x-obj2.posAnterior.x)/vel.x,(obj1.posAnterior.x-col2.getDim().x-obj2.posAnterior.x)/vel.x);
            tempo.y= (vel.y==0)? numeric_limits<float>::max(): min((obj1.posAnterior.y-col1.getDim().y-obj2.posAnterior.y)/vel.y,(obj1.posAnterior.y+col2.getDim().y-obj2.posAnterior.y)/vel.y);
            
            if(fabs(tempo.x)>Tempo::getDeltaTempoFixo())
                tempo.x=numeric_limits<float>::max();
            else 
                tempo.x=fabs(tempo.x);
            if(fabs(tempo.y)>Tempo::getDeltaTempoFixo())
                tempo.y=numeric_limits<float>::max();
            else 
                tempo.y=fabs(tempo.y); 
            Vector2f mov1, mov2;
            if(tempo== Vector2f(numeric_limits<float>::max(),numeric_limits<float>::max()))
                return;
            if(tempo.x<tempo.y)
            {
                
                mov1.x = -obj1.velocidade.x*(Tempo::getDeltaTempoFixo()-tempo.x);
                mov2.x= -obj2.velocidade.x*(Tempo::getDeltaTempoFixo()-tempo.x);
                obj1.velocidade.x=0;
                obj2.velocidade.x=0;
            }
            else
            {
                
                mov1.y = -obj1.velocidade.y*(Tempo::getDeltaTempoFixo()-tempo.y);
                mov2.y= -obj2.velocidade.y*(Tempo::getDeltaTempoFixo()-tempo.y);
                obj1.velocidade.y=0;
                obj2.velocidade.y=0;
            }
            col1.Mover(mov1);
            col2.Mover(mov2);
            obj1.Avisar(obj2);
            obj2.Avisar(obj1);
        }
        
    }
    void ObjetoFisico::Avisar(ObjetoFisico &obj)
    {
        if (corpo != nullptr)
        {
            corpo->AvisarEscuta(&obj);
        }
    }


    void ObjetoFisico::AtualizarPos()
    {
        posAnterior = colisor.getPos();
        colisor.Mover(velocidade*((float)Tempo::getDeltaTempoFixo()));
    }
    CorpoRigido* ObjetoFisico::getCorpoRigido()
    {
        return corpo;
    }
}