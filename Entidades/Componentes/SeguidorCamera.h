#pragma once
#include "Componente.h"
#include "GerenciadorGrafico.h"
#include "Camera.h"
#include "commons.h"
using namespace sf;
using namespace Gerenciadores;
namespace Componentes
{
    class SeguidorCamera: public Componente
    {
        private:
            float velAcompanhamento;
            float limEsq,limDir,limCima,limBaixo;
            void Iniciar();
            void AtualizarFixo();
            void SeguirJogadores();
            void Atualizar();
        public:
            SeguidorCamera(const float vel=0.3,const float limEsq=0,const float limDir=40,const float limCima=10,const float limBaixo=-6,const Vector2f posInit = Vector2f(0,0),const Vector2f dimCam=Vector2f(10,7));
            ~SeguidorCamera(){}

    };
}