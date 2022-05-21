#pragma once
#include "commons.h"
#include "Camera.h"
#include "Imagem.h"
using namespace sf;
using namespace std;
using namespace Graficos;
//max de layers graficos
#define LAYERS_MAX 5
//layers de ui
#define UI_MAX 5
namespace Gerenciadores{
    class GerenciadorGrafico
    {
        private:
            float tempUltRender = 0;
            RenderWindow* window;
            static Vector2f posCamTela;
            
            static list<Imagem*> UI[];
            static list<Imagem*> layers[]; 
            static Color corBorda;
            static Color corFundo;
        public:
            static Camera cam;
            static void addNoLayer(Imagem* img, int layer);
            static void addUI(Imagem* img, int layer);
            //pos na tela de um ponto no espaco global
            static const Vector2f PosGlobalParaTela(const Vector2f pos);
            //pos no espaco global de um ponto na tela
            static const Vector2f PosTelaParaGlobal(const Vector2f pos);
            //posicao na tela de um ponto no espaco de ui
            static const Vector2f PosUiParaTela(const Vector2f pos);
            //posicao no espaco do ui de um ponto na tela
            static const Vector2f PosTelaParaUi(const Vector2f pos);
            //testa se ponto esta dentro da camera
            static const bool posNaCam(const Vector2f pos);
            static void setCorBorda(const Color cor);
            static void setCorFundo(const Color cor);
            //renderiza e retorna quantos frames passaram
            void Render();
            GerenciadorGrafico(RenderWindow* win = nullptr)
            : window(win) {}
            ~GerenciadorGrafico();

    };

}