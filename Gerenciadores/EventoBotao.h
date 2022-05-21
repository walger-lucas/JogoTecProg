#pragma once
#include "GerenciadorInputs.h"
#include"commons.h"
#include"Colisor.h"
using namespace sf;
using namespace std;
using namespace Colisoes;

namespace Gerenciadores
{
    class EventoBotao
    {
        private:
            Colisor col;
            bool ativo;
            bool clicadoNoUltimoTeste;
            function<void()> funcApertar;
            function<void()> funcDesapertar;
        public:
            
            void Apertar(Vector2f pos);
            void Desapertar();
            void setPonteiros(Vector2f* pos,Vector2f* dim);
            const bool getAtivo() const;
            void setAtivo(const bool atv);
            void setFuncApertar(function<void()> func);
            void setFuncDesapertar(function<void()> func);
            EventoBotao(Vector2f* pos, Vector2f* dim);
            EventoBotao();
            ~EventoBotao();

    };
}