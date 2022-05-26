#pragma once
#include "ControleInimigo.h"
#include "GraficoSprite.h"
namespace Componentes
{
    class ControleExplodidor: public ControleInimigo
    {
        private:
        const float recarga;
        float cont_recarga;
        float velocidade;
        float distAtv;
        Texture comEspinhos;
        Texture semEspinhos;

        void Colidiu(ObjetoFisico* obj);
        void Atualizar();
        void AtualizarFixo();
        void ExplodirEspinhos();
        void Iniciar();

        public:
            ControleExplodidor(float recarga = 1000);
            ~ControleExplodidor();
    };
}
