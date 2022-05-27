#pragma once
namespace Componentes
{
    class Movimento
    {
        public:

            ~Movimento(){};
            Movimento(const float vel=2,const float pulo=4,bool recuperar = true,const float recuperacao = 0.4);
            const float getVelocidade() const;
            const float getPulo() const;
            void setModPulo(float mod);
            void setModVelocidade(float mod);
        protected:
            const float velocidade,pulo;
            float modVelocidade,modPulo;
            //aumento percentual por segundo dos modificadores para chegar em 1.
            const float deltaRecargaMods;
            bool recuperar;
            //recupera aos poucos os modificadores a 1;
            void RecuperarMods();
            
        


    };
}