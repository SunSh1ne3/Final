#pragma once
#include<SFML\Graphics.hpp>

namespace av
{
    class Avto
    {
    public:
        Avto(int x, int y, float a);

        bool Setup();
        
        float Get_A();
        
        int Get_x();
       
        void Set_x(int x);
       
        int Get_y();
        
        void Set_y(int y);

        void Move(float x, float y);

        sf::Sprite* Get();

        ~Avto();

        
    private:
        int m_x, m_y;
        float m_a;
        sf::Texture m_texture;
        sf::Sprite* m_avto = nullptr;

    };
}