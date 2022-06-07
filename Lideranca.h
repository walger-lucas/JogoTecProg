#include "commons.h"
using namespace std;
class Lideranca
{
    private:
        class Lider
        {
            private:
                string nome;
                int pontos;
            public:
                void escreverDados(ofstream& stream);
                const string getInfo();
                Lider(ifstream& stream);
                Lider(const string& nome, const int pontos);
                ~Lider();
                const bool operator<(const Lider& lider);
                const bool operator>(const Lider& lider);
                const bool operator==(const Lider& lider);
        };
        static vector<Lider> lideres;
    public:
        static int numeroLideres();
        static const string getInfo(int primeiro=0,int ultimo=lideres.size());
        static void addLider(const string nome, int pontos);
        static void CarregarLideres();
        static void SalvarLideres();
};