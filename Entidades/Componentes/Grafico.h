#pragma once
#include"Imagem.h"
#include"commons.h"
#include"Componente.h"
#include"Posicao.h"
#include"GerenciadorGrafico.h"
using namespace std;
using namespace sf;
using namespace Graficos;
using namespace Gerenciadores;
namespace Componentes{
    class Grafico: public Componente
    {
        protected:
            virtual void  Render(){};
            virtual Imagem* Construir() = 0;
        private:
            Imagem* img;
            bool ui;
            bool inicializado = false;
            int layer;//layer onde esta localizado a imagem
            void Iniciar();
        public:
            Grafico(int layer=0,bool ui=false,Imagem* img=nullptr)
            : Componente(), img(img), ui(ui),layer(layer)
            {}
            virtual ~Grafico();
            void setAtivado(bool atv);
        

    };
}