#include <cars.hpp>
#include <iostream>

namespace cr
{
        Cars::Cars(int x, int y, float a, float b, float velocity)
        {
            m_x = x;
            m_y = y;
            m_a = a;
            m_b = b;
            m_velocity = velocity;
            //m_index = index;
        }

        bool Cars::Setup()
        {
            if (!m_texture.loadFromFile("Textures/cars.png"))
            {
                std::cout << "Error with avto texture!!!" << std::endl;
                return false;
            }
            m_cars = new sf::Sprite();
            m_cars->setTexture(m_texture);
            m_cars->setOrigin(m_a / 2, m_b / 2);
            m_cars->setPosition(m_x, m_y);

            return true;
        }

        int Cars::Get_x()
        {
            return m_x;
        }

        void Cars::Set_x(int x)
        {
            m_x = x;
            m_cars->setPosition(m_x, m_y);
        }

        int Cars::Get_y()
        {
            return m_y;
        }
        void Cars::Set_y(int y)
        {
            m_y = y;
            m_cars->setPosition(m_x, m_y);
        }
        void Cars::Move()
        {
            m_y += m_velocity;
            m_cars->setPosition(m_x, m_y);
        }

        void Cars::setVelocity(float velocity)
        {
            m_velocity = velocity;
            m_cars->setPosition(m_x, m_y);
        }

        sf::Sprite* Cars::Get()
        {
            return m_cars;
        }

        Cars::~Cars()
        {
            delete m_cars;
        }

}