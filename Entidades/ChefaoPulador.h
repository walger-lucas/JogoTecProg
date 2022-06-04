#include "Entidade.h"
#include "ControleChefaoPulador.h"
#include "commons.h"
namespace Entidades
{
    class ChefaoPulador: public Entidade
    {
        private:
            Vida* vida;
            Posicao* pos;
            CorpoRigido* cR;
            GraficoSprite* gS;
            ControleChefaoPulador* cCP;
            Texture coelho;
            static int id;
            static list<ChefaoPulador*> puladores;
            void escreverDadosPessoal(ofstream& stream);
            static void lerDadosPessoal(ifstream& stream,Cena* cena);
            void escreverRelacoesPessoal(ofstream& stream);
            static void lerRelacoesPessoal(ifstream& stream,Cena* cena);
            void Carregar();
        public:
            static void lerDados(ifstream& stream, Cena* cena);
            static void escreverDados(ofstream& stream);
            static void escreverRelacoes(ofstream& stream);
            const static string TAG_CHEFAO;
            ChefaoPulador(Vector2f pos);
            ~ChefaoPulador();
    };
}