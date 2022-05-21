#pragma once
#include"commons.h"
#define FONTE_PATH "./Arquivos/Fontes/"
#define IMAGEM_PATH "./Arquivos/Imagens/"
using namespace sf;
using namespace std;
namespace Gerenciadores
{
    class GerenciadorArquivos
    {
        private:
            static unordered_map<string,Texture> texturas;
            static unordered_map<string,Font> fontes;
            GerenciadorArquivos(){}
            ~GerenciadorArquivos(){}
        public:
            static void CarregarTextura(const string& nome, const string& path);
            static void CarregarFonte(const string& nome, const string& path);
            static void DescarregarTextura(const string& nome);
            static void DescarregarFonte(const string& nome);
            static Texture* getTextura(const string& nome);
            static Font* getFonte(const string& nome);

    };
}
