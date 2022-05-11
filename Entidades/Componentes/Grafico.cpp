#include"Grafico.h"
using namespace sf;
using namespace std;
namespace Componentes{
    void Grafico::Iniciar()
    {
        inicializado = true;
        img=Construir();
        
        if(img==nullptr) 
            return;     
        if(ui)
            GerenciadorGrafico::addUI(img,layer);
        else
            GerenciadorGrafico::addNoLayer(img,layer);
         
    }
    Grafico::~Grafico()
    {
        if(!inicializado)
        {
            delete img;
        }
        else
        {
            img->Destruir();
        }
    }
    void Grafico::setAtivado(bool atv)
    {
        Componente::setAtivado(atv);
        img->setAtivo(atv);
    }
}