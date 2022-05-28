#pragma once
#include "SeguidorCamera.h"
#include "Entidade.h"
using namespace Componentes;
namespace Entidades
{
    class ControladorUI: public Entidade
    {
        private:
            SeguidorCamera* sC;
            void Carregar(){};
        public:
            ControladorUI(float limCima,float limBaixo,float limDir,float limEsq,float vel)
            {
                sC = new SeguidorCamera(vel,limEsq,limDir,limCima,limBaixo);
                addComponente(sC);
            }
            ~ControladorUI(){};
    };
}