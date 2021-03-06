#pragma once
#include"commons.h"
#include"Colisor.h"
using namespace std;
using namespace sf;
namespace Componentes
{
    class CorpoRigido;
}
using namespace Componentes;
namespace Colisoes{
    class ObjetoFisico{
        private:
            Colisor colisor;//colisor com posicao e dimensao do objeto
            bool colidivel, //avisa se eh possivel colidir com esse objeto, ele ainda recebe avisos se algo interno.
                cinematico, //avisa se esse objeto pode se mover
                ativo,//avisa se esse objeto deve ser simulado
                destruir; //avisa se esse objeto deve ser destruido
            Vector2f velocidade;//guarda a velocidade do objeto
            Vector2f posAnterior;
            CorpoRigido* corpo;

        public:
        void AtualizarPos();
        const bool getColidivel() const;
        const bool getCinematico() const;
        const bool getAtivo() const;
        const bool getDestruir() const;
        const Vector2f getVel() const;
        Colisor& getColisor();
        void setColidivel(const bool col);
        void setCinematico(const bool cine);
        void setAtivo(const bool atv);
        void setVel(const Vector2f vel);
        void addVel(const Vector2f vel);
        void Destruir();
        static void Resolver(ObjetoFisico& obj,ObjetoFisico& obj2);
        void Avisar(ObjetoFisico& obj);
        CorpoRigido* getCorpoRigido();

        ObjetoFisico(Vector2f* pos=nullptr, Vector2f* dim=nullptr,CorpoRigido* corpo=nullptr,bool col=true, bool cine=false)
        :colisor(pos,dim),colidivel(col),cinematico(cine),ativo(true),destruir(false),corpo(corpo)
        {
            velocidade=Vector2f(0,0);

        }
        ~ObjetoFisico()
        {}



    };
}