#pragma once
#include"commons.h"
#include"Componente.h"
#include"Entidade.h"
#include"ObjetoFisico.h"
#include"IEscutaColisao.h"
using namespace std;
using namespace sf;
using namespace Colisoes;
namespace Componentes
{
    class CorpoRigido: public Componente
    {
        private:
            bool gravidade;
            const bool colidivel,cinematico;
            const float massa;
            ObjetoFisico* obj;
            vector<IEscutaColisao*> escutas;
        protected:
            Vector2f dimensao;
            void Iniciar();
            void AtualizarFixo();
        public:
            const Vector2f getVelocidade() const;
            const Vector2f getDim() const;
            void setDim(const Vector2f dim);
            const bool getGravidade() const;
            const float getMassa() const;
            void setMassa(const float massa);
            void setVelocidade(const Vector2f vel);
            void setGravidade(const bool grav);
            void addEscuta(IEscutaColisao* escuta);
            void AvisarEscuta(ObjetoFisico* obj);
            void setColidivel(const bool col);
            void setCinematico(const bool cine);
            void setAtivado(const bool atv);

            CorpoRigido( const bool colidivel=true, const bool cinematico=false,const float massa =1, bool gravidade=true)
            : Componente(),gravidade(gravidade), colidivel(colidivel),
            cinematico(cinematico),massa(massa), obj(nullptr), dimensao(1,1)
            {
                escutas.clear();
            }
            ~CorpoRigido()
            {
                if(obj!=nullptr)
                    obj->Destruir();
            }


            
    };
}