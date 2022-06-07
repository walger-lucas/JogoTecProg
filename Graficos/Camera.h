#ifndef _CAMERA_H
#define _CAMERA_H
#include"commons.h"
#include"Colisor.h"
using namespace sf;
using namespace Colisoes;
namespace Graficos{
    class Camera{
        private:
            //posicao da camera no espaco do jogo
            Vector2f posicao;
            //dimensao da tela vista em pixeis
            Vector2f dimensao;
            //Pixeis por unidade de movimento
            static float pixPorUnidade;
        public:
            static const float getPPU();
            static void setPPU(const float ppu);
            const Vector2f getPos() const;
            const Vector2f getDim() const;
            const Vector2f getCentro() const;
            void setPos(const Vector2f pos);
            void setDim(const Vector2f dim);
            //move camera por offset
            void Mover(const Vector2f movimento);
            //seta centro de camera na posicao centro
            void Centralizar(const Vector2f centro);
            //retorna se colisor aparece na camera
            const bool BoxDentro(const Colisor& col) const;
            const bool BoxDentro(const Vector2f& pnt) const;
            //posicao em pixels da visao da camera
            //global para cam
            const Vector2f PosicaoVisCamera(const Vector2f pos) const;
            //cam para global
            const Vector2f PosicaoVisGlobal(const Vector2f pos) const;
            const Vector2f PosUiTela(const Vector2f pos) const;
            const Vector2f PosTelaUi(const Vector2f pos) const;

            Camera(const Vector2f pos = Vector2f(0,0),const Vector2f dim=Vector2f(10,7))
            : posicao(pos), dimensao(dim)
            {}
            ~Camera()
            {}
    };
    
}
#endif