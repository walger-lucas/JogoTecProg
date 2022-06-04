#pragma once
#include "SeguidorCamera.h"
#include "Entidade.h"
#include "VidaUI.h"
using namespace Componentes;
namespace Entidades
{
    class ControladorUI: public Entidade
    {
        private:
            SeguidorCamera* sC;
            VidaUI* vd;
            void Carregar(){};
        public:
            ControladorUI(float limCima,float limBaixo,float limDir,float limEsq,float vel)
            {
                sC = new SeguidorCamera(vel,limEsq,limDir,limCima,limBaixo);
                vd= new VidaUI();
                addComponente(vd);
                addComponente(sC);
                
            }
            ~ControladorUI(){};
    };
}