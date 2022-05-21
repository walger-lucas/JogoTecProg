#include"GerenciadorGrafico.h"
using namespace std;
using namespace sf;
using namespace Graficos;

namespace Gerenciadores{
    
    Camera GerenciadorGrafico::cam= Camera();
    list<Imagem*> GerenciadorGrafico::UI[UI_MAX]={list<Imagem*>()};//inicializa static
    list<Imagem*> GerenciadorGrafico::layers[LAYERS_MAX]={list<Imagem*>()};//inicializa static
    Vector2f GerenciadorGrafico::posCamTela(0,0);
    Color GerenciadorGrafico::corBorda= Color::Black;
    Color GerenciadorGrafico::corFundo= Color::White;


    GerenciadorGrafico::~GerenciadorGrafico()
    {
        //desaloca todas as imagens
        for(int i=0;i<LAYERS_MAX;i++)
        {
            for(auto it : layers[i])
            {
                delete it;
            }
            layers[i].clear();
        }
        for(int i=0;i<UI_MAX;i++)
        {
            for(auto it : UI[i])
            {
                delete it;
            }
            UI[i].clear();
        }    
    }

    void GerenciadorGrafico::addNoLayer(Imagem* img,int layer)
    {
        if(layer>=0&&layer<LAYERS_MAX)
            layers[layer].push_back(img);
    }
    void GerenciadorGrafico::addUI(Imagem* img,int layer)
    {
        if(layer>=0&&layer<UI_MAX)
            UI[layer].push_back(img);
    }

    const Vector2f GerenciadorGrafico::PosGlobalParaTela(const Vector2f pos)
    {
        return posCamTela+cam.PosicaoVisCamera(pos);
    }
    const Vector2f GerenciadorGrafico::PosTelaParaGlobal(const Vector2f pos)
    {
        return cam.PosicaoVisGlobal(pos-posCamTela);
    }
    const bool GerenciadorGrafico::posNaCam(const Vector2f pos){
        return cam.BoxDentro(PosTelaParaGlobal(pos));
    }

    const Vector2f GerenciadorGrafico::PosUiParaTela(const Vector2f pos)
    {
        return posCamTela+ cam.PosUiTela(pos);
    }
    const Vector2f GerenciadorGrafico::PosTelaParaUi(const Vector2f pos)
    {
        return cam.PosTelaUi(pos-posCamTela);
    }


    void GerenciadorGrafico::Render()
    {
        //maybe isso vai pra Principal
        /* Apenas quando tempo estiver presente
        tempUltRender+=Tempo::getDeltaTempo();
        if(tempUltRender<Tempo::getDeltaTempoRender())
            return;
        tempUltRender=0;
        */
        Vector2u dim =window->getSize();
        Vector2f dimCam = cam.getDim();

        //descobre ppu
        float ppu =dim.x/dimCam.x;
        bool xCompleto = true;
        if(ppu*dimCam.y>dim.y)
        {
            ppu = dim.y/dimCam.y;
            xCompleto = false;
        }
        cam.setPPU(ppu);
        //centraliza tela
        posCamTela = Vector2f((dim.x - dimCam.x*cam.getPPU())*0.5,(dim.y - dimCam.y*cam.getPPU())*0.5);
        window->clear(corFundo);//Limpa Tela
        int i;
        Drawable* desenho;
        //renderiza layers comuns
        for(i=0;i<LAYERS_MAX;i++)
        {

            for(list<Imagem*>::iterator it = layers[i].begin();it!=layers[i].end();it++)
            {
                if((*it)->getDestruir())//testa se deve destruir imagem
                {
                    delete *it;
                    layers[i].erase(it);
                }
                else if((*it)->getAtivo())
                {
                    desenho=(*it)->Desenhar();
                    if(desenho!=nullptr)
                        window->draw(*desenho);
                }
            }
        }
        //renderiza todos os layers de UI
        for(i=0;i<UI_MAX;i++)
        {

            for(list<Imagem*>::iterator it = UI[i].begin();it!=UI[i].end();it++)
            {
                if((*it)->getDestruir())//testa se deve destruir imagem
                {
                    delete *it;
                    UI[i].erase(it);
                }
                else if((*it)->getAtivo())
                {
                    desenho=(*it)->DesenharUI();
                    if(desenho!=nullptr)
                        window->draw(*desenho);
                }
            }
        }

       //encontra tamanho das barras limitadoras
        Vector2f barSize= xCompleto? Vector2f(dim.x,(dim.y-dimCam.y*ppu)*0.5) :Vector2f((dim.x-dimCam.x*ppu)*0.5,dim.y);
        //Cria bordas da tela
        RectangleShape rect(barSize);
        rect.setFillColor(corBorda);
        rect.setPosition(0,0);
        window->draw(rect);
        Vector2f pos2 = xCompleto? Vector2f(0,(dim.y+dimCam.y*ppu)*0.5) : Vector2f((dim.x+dimCam.x*ppu)*0.5,0);
        rect.setPosition(pos2);
        window->draw(rect);
        //-------------------------------------
        window->display();
    }
    void GerenciadorGrafico::setCorBorda(const Color cor)
    {
        corBorda=cor;
    }
    void GerenciadorGrafico::setCorFundo(const Color cor)
    {
        corFundo=cor;
    }
}