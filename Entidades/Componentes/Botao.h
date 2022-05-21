#pragma once
#include "commons.h"
#include "EventoBotao.h"
#include "ImgTexto.h"
#include "ImgSprite.h"
#include "GraficoSprite.h"
#include "Componente.h"
#include "Posicao.h"
#include"GerenciadorArquivos.h"

using namespace std;
using namespace sf;
using namespace Graficos;

namespace Componentes
{
    class Botao: public Componente
    {
        private:
            Vector2f dimensao;
            ImgTexto* texto;
            EventoBotao botao;
            void Iniciar();

            //guardado para incializacao quando possivel
            Texture* textura;

        public:
            void setAtivado(bool atv);
            void setTexto(const string& texto);
            void setFonte(Font& fonte);
            void setTexturaBotao(Texture* txt);
            void setFuncApertar(function<void()> apertar);
            void setFuncDesapertar(function<void()> desapertar);
            void setOffsetTexto(Vector2f offset);
            void setTamanhoTexto(const float tam);
            Botao(Texture* texura=GerenciadorArquivos::getTextura("button0"),const string texto=""
            , Font* fonte=GerenciadorArquivos::getFonte("arial"), 
            Vector2f offset=Vector2f(0,0), float tam=0.3);
            ~Botao();
            
        
    };
}
