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
        public:
            
            void Apertar(Vector2f pos);
            const bool getAtivo() const;
            void setAtivo(const bool atv);
            EventoBotao(Vector2f* pos, Vector2f* dim);
            EventoBotao();
            ~EventoBotao();
            
        protected:
            virtual void BotaoApertado()=0;

    };
}