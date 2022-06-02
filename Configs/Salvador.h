#pragma once
#include "commons.h"
#include "Cena.h"
using namespace std;
namespace Configs
{
    class Salvador
    {
        private:
            
            int saveAtual=-1;
            int savesSalvos=0;
            void SalvarListaSaves();

            class Save
            {
                private:
                    string nome;
                    int pontos;
                    int fase;
                    bool doisJogadores;
                public:
                    const string& getNome() const;
                    const int& getPontos() const;
                    const int& getFase() const;
                    const bool& getDoisJogadores() const;
                    void setNome(const string& nome);
                    void setPontos(const int& pontos);
                    void setFase(const int& fase);
                    void setDoisJogadores(const bool& dJ);
                    void writeDados(ofstream& stream);
                    void readDados(ifstream& stream);
                    Save(const string& nome="", const int pontos=0,const int fase=-1,const bool doisJog=false);
                    ~Save();
            };
            Save savesNome[5];
        public:
            static Salvador* salvador;
            const string getNome(int id);
            const int getSavesSalvos() const;
            void salvarNovoJogo(int id,const std::string& nome);
            void AbrirListaSaves();
            const int getIdSaveAtual();
            void carregarSave(int id);
            void carregarCena(Cena* cena);
            
            Salvador();
            ~Salvador();
    };
}