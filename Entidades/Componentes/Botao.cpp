#include"Botao.h"
#include "Entidade.h"
#include "GerenciadorArquivos.h"
using namespace std;
using namespace sf;
using namespace Graficos;
using namespace Entidades;
using namespace Gerenciadores;

namespace Componentes
{
    void Botao::setAtivado(bool atv)
    {
        Componente::setAtivado(atv);
        texto->setAtivo(atv);
        botao.setAtivo(atv);
    }
    void Botao::setFonte(Font& font)
    {
        texto->setFont(font);
    }
    void Botao::setFuncApertar(function<void()> func)
    {
        botao.setFuncApertar(func);
    }
    void Botao::setFuncDesapertar(function<void()> func)
    {
        botao.setFuncDesapertar(func);
    }
    void Botao::setTamanhoTexto(const float tam)
    {
        texto->setTam(tam);
    }
    void Botao::setOffsetTexto(Vector2f offset)
    {
        texto->setOrigin(offset);
    }
    void Botao::setTexturaBotao(Texture* txt)
    {
        GraficoSprite* graf = getEntidade()->getComponente<GraficoSprite>();
        if(graf!=nullptr)
        {
            ImgSprite* img = graf->getSprite();
            img->setTextura(*txt);
            dimensao = Vector2f(img->getDim().x*img->getEscala().x,img->getDim().y*img->getEscala().y);
        }
        else
        {
            cout<< "ERRO : IMPOSSIVEL ENTIDADE TER COMPONENTE BOTAO SEM COMPONENTE GRAFICOSPRITE\n";
        }
    }
    void Botao::setTexto(const string& txt)
    {
        texto->setTexto(txt);
    }
    Botao::Botao(Texture* texture,const string texto, Font* fonte, Vector2f offset, float tam)
    :dimensao(1,1),textura(texture)
    {
        this->texto = new ImgTexto(nullptr,tam);
        this->texto->setFont(*fonte);
        this->texto->setTexto(texto);
        this->texto->setOrigin(offset);
        this->texto->setTam(tam);
        this->texto->setAtivo(false);
        botao.setAtivo(false);
    }
    Botao::~Botao()
    {
        if(texto!=nullptr)
            texto->Destruir();
    }
    void Botao::Iniciar()
    {
        Posicao* pos = getEntidade()->getComponente<Posicao>();
        if(pos!=nullptr)
        {
            texto->setPPos(pos->getPPos());
            botao.setPonteiros(pos->getPPos(),&dimensao);
            setTexturaBotao(textura);
            texto->setAtivo(true);
            botao.setAtivo(true);
            GerenciadorGrafico::addUI(texto,3);
            
        }
        else
        {
            cout<<"ERRO: ENTIDADE PRECISA DE COMPONENTE POSICAO PARA TER COMPONENTE BOTAO"<<endl;
        }
        
    }

}