#pragma once
#include<SFML\Graphics.hpp>

namespace cr
{
    class Cars
    {
    public:
        Cars(int x, int y, float a, float b, float velocity);

        bool Setup();

        int Get_x();

        void Set_x(int x);

        int Get_y();

        void Set_y(int y);

        void Move();

        void setVelocity(float velocity);

        sf::Sprite* Get();
       
        ~Cars();

      //  int index;
    private:
        int m_x, m_y;
        float m_a, m_b;
        float m_velocity;
        
        sf::Texture m_texture;
        sf::Sprite* m_cars = nullptr;

    };
}