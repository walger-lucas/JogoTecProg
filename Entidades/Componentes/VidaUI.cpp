#include "VidaUI.h"
#include "commons.h"
using namespace Gerenciadores;
namespace Componentes
{
    VidaUI::VidaUI()
    :Componente(),pos1(0.2,0),pos2(0.2,-1.2),pos3(7,0),esc1(1,1),esc2(1,1)
    {
        jimmy = nullptr;
        janny = nullptr;
        pontos = nullptr;
        for(int i =0;i<2;i++)
            vida[i].loadFromFile("Arquivos/Imagens/Vida/vida4.png");
            
        jimmy = new ImgSprite(&pos1,&esc1);
        jimmy->setTextura(vida[0]);
        GerenciadorGrafico::addUI(jimmy,0);
        if(Jogador::SaoDoisJogadores())
        {
            janny=new ImgSprite(&pos2,&esc2);
            janny->setTextura(vida[1]);
            GerenciadorGrafico::addUI(janny,0);
        }
        pontos = new ImgTexto(&pos3,0.7);

        guest3d.loadFromFile("Arquivos/Fontes/Guest3D.ttf");
        pontos->setFont(guest3d);
        pontos->setPixChar(120);
        pontos->setTexto(to_string(Jogador::getPontos()));
        GerenciadorGrafico::addUI(pontos,0);

    }
    VidaUI::~VidaUI()
    {
        if(jimmy)
            jimmy->Destruir();
        if(janny)
            janny->Destruir();
        if(pontos)
            pontos->Destruir();
    }
    void VidaUI::Render()
    {
        if(jimmy)
        {
            vida[0].loadFromFile("Arquivos/Imagens/Vida/vida"+to_string(Jogador::vidasJogador(0))+".png");
            jimmy->setTextura(vida[0]);
        }
        if(janny&&Jogador::SaoDoisJogadores())
        {
            vida[1].loadFromFile("Arquivos/Imagens/Vida/vida"+to_string(Jogador::vidasJogador(1))+".png");
            janny->setTextura(vida[1]);
        }
        if(pontos)
            pontos->setTexto(to_string(Jogador::getPontos()));
    }
}