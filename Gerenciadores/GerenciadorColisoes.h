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
            static bool tenteDestruir(list<ObjetoFisico*>::iterator& it);
            
        public:
            static const float gravidade;
            static void AddObjeto(ObjetoFisico* obj);
            //encontra colisao com ponto e colisor
            static list<ObjetoFisico*> EncontraColisao(Vector2f ponto);
            static list<ObjetoFisico*> EncontraColisao(Colisor& colisor);
            void Atualizar();
            void ResolverColisoes();

            GerenciadorColisoes()
            {}
            ~GerenciadorColisoes()
            {}
    };
}