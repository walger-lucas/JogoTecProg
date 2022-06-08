#include "SeguidorCamera.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Tempo.h"
#include "Cena.h"
#include "Jogo.h"
#include "MenuPause.h"
#include "MenuMorte.h"
using namespace Entidades;
using namespace Gerenciadores;
using namespace Configs;
namespace Componentes
{
    void SeguidorCamera::Iniciar()
    {

    }
    void SeguidorCamera::AtualizarFixo()
    {
        SeguirJogadores();
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            Jogo::MenuAtual(new Menus::MenuPause());
        } 
        if(Jogador::vidasJogador(0)==0 && Jogador::vidasJogador(1)==0)
        {
            Jogo::MenuAtual(new Menus::MenuMorte());
        }
        
    }
    void SeguidorCamera::Atualizar()
    {

    }
    Vector2f lerp(Vector2f a,Vector2f b , float f)
    {
        return a + (b-a)*f;
    }
    void SeguidorCamera::SeguirJogadores()
    {
        if(Jogador::JogadoresVivos())
        {
            Vector2f centro = lerp(GerenciadorGrafico::cam.getCentro(),Jogador::localizacaoMediaJogadores(),velAcompanhamento*Tempo::getDeltaTempoFixo());
            GerenciadorGrafico::cam.Centralizar(centro);
            Vector2f pos =  GerenciadorGrafico::cam.getPos();
            Vector2f dim =  GerenciadorGrafico::cam.getDim();
            if(pos.x<limEsq)
                GerenciadorGrafico::cam.setPos(Vector2f(limEsq,pos.y));
            else if(pos.x+dim.x>limDir)
                GerenciadorGrafico::cam.setPos(Vector2f(limDir-dim.x,pos.y));
            pos =  GerenciadorGrafico::cam.getPos();
            if(pos.y>limCima)
                GerenciadorGrafico::cam.setPos(Vector2f(pos.x,limCima));
            else if (pos.y-dim.y<limBaixo)
                GerenciadorGrafico::cam.setPos(Vector2f(pos.x,limBaixo+dim.y));

        }
    }
    SeguidorCamera::SeguidorCamera(const float vel,const float limEsq,const float limDir,const float limCima,const float limBaixo,const Vector2f posInit,const Vector2f dimCam)
    {
        this->velAcompanhamento = vel;
        this->limEsq=std::min(limEsq,limDir);
        this->limDir=std::max(limEsq,limDir);
        this->limBaixo=std::min(limBaixo,limCima);
        this->limCima=std::max(limBaixo,limCima);
        GerenciadorGrafico::cam.setPos(posInit);
        GerenciadorGrafico::cam.setDim(dimCam);
    } 
}
