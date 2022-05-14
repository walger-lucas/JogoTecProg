#pragma once
#include"commons.h"
#include"Colisor.h"
#include"ObjetoFisico.h"
using namespace sf;
using namespace std;
using namespace Colisoes;
namespace Gerenciadores{
    class GerenciadorColisoes{
        private:
            static list<ObjetoFisico*> objetos;
            static const int atualizacaoMax;
            static float tempoUltAtualizacao;
            static bool tenteDestruir(list<ObjetoFisico*>::iterator& it);
            void ResolverColisoes();
        public:
            static const float tempoFixo;
            static const float gravidade;
            static void AddObjeto(ObjetoFisico* obj);
            //encontra colisao com ponto e colisor
            static list<ObjetoFisico*> EncontraColisao(Vector2f ponto);
            static list<ObjetoFisico*> EncontraColisao(Colisor& colisor);
            void Atualizar();

            GerenciadorColisoes()
            {}
            ~GerenciadorColisoes()
            {}
    };
}