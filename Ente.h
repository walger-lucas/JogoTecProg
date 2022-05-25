#pragma once

class Ente
{
    private:
        static int id_count;
        int id;
        virtual void Atualizar()=0;
        virtual void Render() =0;
        virtual void AtualizarFixo()=0;
    public:
        Ente()
        :id(id_count++)
        {}
        ~Ente(){};
};

