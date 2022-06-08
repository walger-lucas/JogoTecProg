#include "Lideranca.h"
vector<Lideranca::Lider> Lideranca::lideres = vector<Lideranca::Lider>();
Lideranca::Lider::Lider(ifstream& stream)
{
    try
    {
        int size;
        stream.read((char*)&size,sizeof(int));
        char* nomeC = new char[size+1];
        stream.read(nomeC,size*sizeof(char));
        nomeC[size]='\0';
        nome=nomeC;
        delete [] nomeC;
        stream.read((char*)&pontos,sizeof(int));
    }
    catch(const std::ifstream::failure &e)
    {
        cerr<<"Nao foi possivel ler lider!\n";
    }
}
Lideranca::Lider::Lider(const string& nome="",const int pontos=0)
:nome(nome),pontos(pontos)
{

}
const bool Lideranca::Lider::operator<(const Lider& lider)
{
    return pontos<lider.pontos;
}
const bool Lideranca::Lider::operator>(const Lider& lider)
{
    return pontos>lider.pontos;
}
const bool Lideranca::Lider::operator==(const Lider& lider)
{
    return this->nome == lider.nome;
}

Lideranca::Lider::~Lider()
{}
void Lideranca::Lider::escreverDados(ofstream& stream)
{
    try
    {
        int size = nome.size();
        stream.write((char*)&size,sizeof(int));
        size = nome.size();
        stream.write(nome.data(),sizeof(char)*size);
        stream.write((char*)&pontos,sizeof(int));
    }
    catch(const std::ofstream::failure &e)
    {
        cerr<<"Impossivel escrever lider "+nome<<endl;
    }

}
const string Lideranca::Lider::getInfo()
{
    return nome + "\t"+ to_string(pontos);
}
void Lideranca::CarregarLideres()
{
        ifstream saves;
        lideres.clear();
        saves.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try
        {
            saves.open("Arquivos/Saves/lideres.bin",ios::binary|ios::in);
            int size;
            saves.read((char*)&size,sizeof(int));
            for(int i =0;i<size;i++)
            {
                lideres.push_back(Lider(saves));
            }
            saves.close();
        }
        catch(const std::ifstream::failure &e)
        {
            std::cerr << "Lideres nunca criados, ou Corrompidos sendo criado novos agora!" << '\n';
            SalvarLideres();
        }
}
void Lideranca::SalvarLideres()
{
        ofstream saves;
        saves.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try
        {
            saves.open("Arquivos/Saves/lideres.bin",ios::binary|ios::out|ios::trunc);
            int size = lideres.size();
            saves.write((char*) &size,sizeof(int));
            for(int i = 0;i<size;i++)
            {
                lideres[i].escreverDados(saves);
            }
            saves.close();
        }
        catch(const std::ofstream::failure& e)
        {
            std::cerr << "Nao foi possivel criar/salvar a lista de Lideres!" << '\n';
        }
}
void Lideranca::addLider(const string nome, int pontos)
{
    Lider lider(nome,pontos);
    std::vector<Lider>::iterator it;
    for(it = lideres.begin();it!=lideres.end();it++)
    {
        
        if(*it==lider)
        {
            if(*it>lider)
                return;
            else
            {
                lideres.erase(it);
                break;
            }     
        }
    }
    lideres.push_back(lider);
    sort(lideres.begin(),lideres.end(),greater<>());
    SalvarLideres();
}
const string Lideranca::getInfo(int inicial,int final)
{
    int size =lideres.size();
    final = std::min(final,size);
    inicial = min(inicial,final);
    string lideranca="";
    for(int i = inicial;i<final;i++)
    {
        lideranca+= to_string(i+1)+ " - "+lideres[i].getInfo()+"\n";
    }
    return lideranca;

}
int Lideranca::numeroLideres()
{
    return lideres.size();
}