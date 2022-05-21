#pragma once
#include"commons.h"
using namespace sf;
namespace Colisoes{
    class Colisor{
        private:
            Vector2f* posicao; //posicao do vertice superior esquerdo
            Vector2f* dimensao;
        public:
            const Vector2f getPos() const;
            const Vector2f getDim() const;
            const Vector2f getCentro() const;
            void setPPos(Vector2f* pos);
            void setPDim(Vector2f* dim);
            void setPos(const Vector2f pos);
            void setDim(const Vector2f dim);
            void setCentro(const Vector2f centro);
            void Mover(const Vector2f movimento);
            static const bool Colide(const Colisor& col1,const Colisor& col2);
            static const bool Colide(const Colisor& col1,const Vector2f& pos);
            static const Vector2f Interseccao(const Colisor& col1,const Colisor& col2);
            Colisor(Vector2f* pos = nullptr,Vector2f* dim=nullptr)
            : posicao(pos), dimensao(dim)
            {}
            ~Colisor(){}
    };
}