#include"GerenciadorArquivos.h"
using namespace sf;
using namespace std;
namespace Gerenciadores{
    unordered_map<string,Texture> GerenciadorArquivos::texturas=unordered_map<string,Texture>();
    unordered_map<string,Font> GerenciadorArquivos::fontes=unordered_map<string,Font>();

    void GerenciadorArquivos::CarregarTextura(const string& nome,const string& path)
    {
        Texture txt;
        if(txt.loadFromFile(IMAGEM_PATH+path))
        {
            texturas.insert({nome,txt});
            cout<<"Textura: "<<IMAGEM_PATH<<path<<" carregada com sucesso!\n";
        }
    }
    void GerenciadorArquivos::CarregarFonte(const string& nome,const string& path)
    {
        Font fnt;
        if(fnt.loadFromFile(FONTE_PATH+path))
        {
            fontes.insert({nome,fnt});
            cout<<"Fonte: "<<FONTE_PATH<<path<<" carregada com sucesso!\n";
        }
    }
    void GerenciadorArquivos::DescarregarTextura(const string& nome)
    {
        texturas.erase(nome);
    }
    void GerenciadorArquivos::DescarregarFonte(const string& nome)
    {
        fontes.erase(nome);
    }
    Texture* GerenciadorArquivos::getTextura(const string& nome)
    {
        return &(texturas[nome]);
    }
    Font* GerenciadorArquivos::getFonte( const string& nome)
    {
        return &(fontes[nome]);
    }
}