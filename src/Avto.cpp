#include <Avto.hpp>
#include <iostream>

namespace av
{
    Avto::Avto(int x, int y, float a)
    {
        m_x = x;
        m_y = y;
        m_a = a;
    }

    bool Avto::Setup()
    {
        if (!m_texture.loadFromFile("Textures/Avto.png"))
        {
            std::cout << "Error with avto texture!!!" << std::endl;
            return false;
        }
        m_avto = new sf::Sprite();
        m_avto->setTexture(m_texture);
        m_avto->setOrigin(m_a / 2, m_a / 2);
        m_avto->setPosition(m_x, m_y);

        return true;
    }

    int Avto::Get_x()
    {
        return m_x;
    }

    void Avto::Set_x(int x)
    {
        m_x = x;
        m_avto->setPosition(m_x, m_y);
    }

    int Avto::Get_y()
    {
        return m_y;
    }

    void Avto::Set_y(int y)
    {
        m_y = y;
    }

    void Avto::Move(float x, float y)
    {
        if (y == -1)
        {
            m_y += 25*y;
            m_avto->setPosition(m_x, m_y);
        }
        else if (y == 1)
        {
            m_y += 25*y;
            m_avto->setPosition(m_x, m_y);
        }
        else if (x == 1)
        {
            m_x += 25*x;
            m_avto->setPosition(m_x, m_y);
        }
        else if (x == -1)
        {
            m_x += 25*x;
            m_avto->setPosition(m_x, m_y);
        }
        else if (y == -2)
        {
            m_y -= 30;
            m_avto->setPosition(m_x, m_y);
        }
    }

    sf::Sprite* Avto::Get()
    {
        return m_avto;
    }

    Avto::~Avto()
    {
        if (m_avto != nullptr)
            delete m_avto;
    }
}