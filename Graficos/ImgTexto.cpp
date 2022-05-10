#include"ImgTexto.h"
#include"GerenciadorGrafico.h"
using namespace std;
using namespace sf;
using namespace Gerenciadores;
namespace Graficos{
    const Vector2f ImgTexto::getPos() const
    {
        return *posicao;
    }
    const float ImgTexto::getTam() const
    {
        return tamanho;
    }
    void ImgTexto::setTam(const float tam)
    {
        tamanho=tam;
    }
    void ImgTexto::setTexto(const string& texto)
    {
        this->texto.setString(texto);
    }
    void ImgTexto::setPixChar(const int pix)
    {
        texto.setCharacterSize(pix);
    }
    void ImgTexto::setFont(const Font& fonte)
    {
        texto.setFont(fonte);
    }
    void ImgTexto::setCor(const Color& cor)
    {
        texto.setFillColor(cor);
    }
    void ImgTexto::setOrigin(const Vector2f pos)
    {
        texto.setOrigin(pos);
    }
    Drawable* ImgTexto::Desenhar()
    {
        if(posicao == nullptr)
            return nullptr;
        //texto.setCharacterSize(tamanho*GerenciadorGrafico::cam.getPPU());
        FloatRect fR = texto.getLocalBounds();
        Vector2f dim(fR.width/GerenciadorGrafico::cam.getPPU(),fR.width/GerenciadorGrafico::cam.getPPU());
        Vector2f pos(*posicao);
        Colisor col(&pos,&dim);
        if(GerenciadorGrafico::cam.BoxDentro(col))
        {
            float size = texto.getCharacterSize();
            texto.setPosition(GerenciadorGrafico::PosGlobalParaTela(*posicao));
            texto.setScale(GerenciadorGrafico::cam.getPPU()*tamanho/size,GerenciadorGrafico::cam.getPPU()*tamanho/size);
            return static_cast<Drawable*>(&texto);
        } 
        return nullptr;
    }

    Drawable* ImgTexto::DesenharUI()
    {
        if(posicao == nullptr)
            return nullptr;
        //texto.setCharacterSize(tamanho*GerenciadorGrafico::cam.getPPU());
        FloatRect fR = texto.getLocalBounds();
        Vector2f dim(fR.width/GerenciadorGrafico::cam.getPPU(),fR.width/GerenciadorGrafico::cam.getPPU());
        Vector2f pos(*posicao);
        Colisor col(&pos,&dim);
        if(GerenciadorGrafico::cam.BoxDentro(col))
        {
            float size = texto.getCharacterSize();
            texto.setPosition(GerenciadorGrafico::PosUiParaTela(*posicao));
            texto.setScale(GerenciadorGrafico::cam.getPPU()*tamanho/size,GerenciadorGrafico::cam.getPPU()*tamanho/size);
            return static_cast<Drawable*>(&texto);
        } 
        return nullptr;
    }
    ImgTexto::ImgTexto(const Vector2f* pos, const float tam)
    : posicao(pos),tamanho(tam)
    {
        texto.setFillColor(Color::Black);
    }
    ImgTexto::~ImgTexto()
    {

    }
    
}
