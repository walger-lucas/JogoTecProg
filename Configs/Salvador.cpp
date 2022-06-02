#include "Salvador.h"
#include "commons.h"
#include "Jogador.h"
#include "GerenciadorCenas.h"
using namespace std;
namespace Configs
{
    Salvador* Salvador::salvador=nullptr;
    Salvador::Salvador()
    {
        
        salvador= this;
        savesSalvos=0;
        AbrirListaSaves();
        
    }
    Salvador::~Salvador()
    {
    }
    void Salvador::AbrirListaSaves()
    {
        ifstream saves;
        saves.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try
        {
            saves.open("Arquivos/Saves/saves.bin",ios::binary|ios::in);
            saves.read((char*)&savesSalvos,sizeof(int));
            for(int i =0;i<savesSalvos;i++)
            {
                savesNome[i].readDados(saves);
            }
            saves.close();
        }
        catch(const std::ifstream::failure &e)
        {
            std::cerr << "Saves nunca criados, ou Corrompidos sendo criado novos agora!" << '\n';
            SalvarListaSaves();
        }
        
    }
    void Salvador::SalvarListaSaves()
    {
        ofstream saves;
        saves.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try
        {
            saves.open("Arquivos/Saves/saves.bin",ios::binary|ios::out|ios::trunc);
            saves.write((char*) &savesSalvos,sizeof(savesSalvos));
            for(int i = 0;i<savesSalvos;i++)
            {
                savesNome[i].writeDados(saves);

            }
            saves.close();
        }
        catch(const std::ofstream::failure& e)
        {
            std::cerr << "Nao foi possivel criar/salvar a lista de saves!" << '\n';
        }
        
    }
    void Salvador::salvarNovoJogo(int id,const std::string& nome)
    {
        if(id>=0&&id<5&& nome!="")
        {
            
            if(savesNome[id].getNome()=="")
                savesSalvos++;
            else
            {
                string nome ="Arquivos/Saves/"+savesNome[id].getNome()+".bin";
                std::remove(nome.data());
            }
            savesNome[id].setNome(nome);
            savesNome[id].setPontos(Jogador::getPontos());
            savesNome[id].setDoisJogadores(Jogador::SaoDoisJogadores());
            savesNome[id].setFase(GerenciadorCenas::getCenaAtual());
            ofstream atual;
            atual.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
            try
            {
                atual.open("Arquivos/Saves/"+savesNome[id].getNome()+".bin",ios::binary|ios::out|ios::trunc);
                Jogador::escreverDados(atual);
                //salvar outras partes
                atual.close();
            }
            catch(const std::ofstream::failure& e)
            {
                std::cerr << "Nao foi possivel salvar save de :"<< nome << '\n';
            }
            
            SalvarListaSaves();
            
        }
    }
    const int Salvador::getIdSaveAtual()
    {
        return saveAtual;
    }
    void Salvador::carregarSave(int id)
    {
        if(id>=0&&id<savesSalvos)
        {
            Jogador::setDoisJogadores(savesNome[id].getDoisJogadores());
            Jogador::zerarPontos();
            Jogador::darPontos(savesNome[id].getPontos());
            GerenciadorCenas::ProximaCena(savesNome[id].getFase());
            Tempo::Pausar(false);
            saveAtual=id;
        }
    }
    void Salvador::carregarCena(Cena* cena)
    {
        
        ifstream atual;
        atual.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try
        {
            atual.open("Arquivos/Saves/"+savesNome[saveAtual].getNome()+".bin",ios::binary|ios::in);
            Jogador::lerDados(atual,cena);
            atual.close();
        }
        catch(const std::ifstream::failure& e)
        {
            std::cerr << "Nao foi possivel abrir o arquivo, corrompido ou nao existente" << '\n';
        }
        
        
        saveAtual=-1;
    }
    const string Salvador::getNome(int id)
    {
        if(id>=0&&id<savesSalvos)
        {
            return savesNome[id].getNome();
        }
        else
            return "Vazio";
    }
    const int Salvador::getSavesSalvos() const
    {
        return savesSalvos;
    }

    Salvador::Save::Save(const string& nome, const int pontos,const int fase,const bool doisJog)
    :nome(nome),pontos(pontos),fase(fase),doisJogadores(doisJog)
    {}
    Salvador::Save::~Save()
    {}
    const string& Salvador::Save::getNome() const
    {
        return nome;
    }
    const int& Salvador::Save::getPontos() const
    {
        return pontos;
    }
    const int& Salvador::Save::getFase() const
    {
        return fase;
    }
    const bool& Salvador::Save::getDoisJogadores() const
    {
        return doisJogadores;
    }
    void Salvador::Save::setNome(const string& nome)
    {
        this->nome=nome;
    }
    void Salvador::Save::setPontos(const int& pontos)
    {
        this->pontos=pontos;
    }
    void Salvador::Save::setFase(const int& fase)
    {
        this->fase=fase;
    }
    void Salvador::Save::setDoisJogadores(const bool& dJ)
    {
        doisJogadores=dJ;
    }
    void Salvador::Save::writeDados(ofstream& stream)
    {
        int size = nome.length();
        stream.write((char*)&size,sizeof(int));
        stream.write(nome.data(),sizeof(char)*size);
        stream.write((char*)&pontos,sizeof(int));
        stream.write((char*)&fase,sizeof(int));
        stream.write((char*)&doisJogadores,sizeof(bool));
        
    }
    void Salvador::Save::readDados(ifstream& stream)
    {
        int size;
        stream.read((char*)&size,sizeof(int));
        char* nomeC = new char[size];
        stream.read(nomeC,sizeof(char)*size);
        nome=nomeC;
        delete [] nomeC;
        stream.read((char*)&pontos,sizeof(int));
        stream.read((char*)&fase,sizeof(int));
        stream.read((char*)&doisJogadores,sizeof(bool));
    }

}