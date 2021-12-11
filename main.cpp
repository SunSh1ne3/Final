#include <SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <vector>
#include <iostream>
#include <Avto.hpp>
#include <Cars.hpp>

using namespace cr;
using namespace av;
using namespace std::chrono_literals;

int main()
{
    float a = 260;
    float a1 = 190;
    float b1 = 250;
    sf::Texture texture;
    if (!texture.loadFromFile("Textures/doroga.jpg"))
    {
        std::cout << "File doroga.jpg not found!" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);

    float x0 = 1000, y0 = 1000;
    sf::RenderWindow window(sf::VideoMode(x0, y0), "Final!");

    //main avto
    Avto* avto = nullptr;
    avto=new Avto(x0 / 2, y0 - 2 * a, a);
    if (!avto->Setup())
    {
        delete avto;
        window.close();
        return -1;
    }

    //cars
    std::vector<Cars*> cars;
    for (int i =a1*0.9; i <= x0-a1/2; i += a1*1.8)
        cars.push_back(new Cars(i, 0, a1, b1, rand() % 35+30));

    for (const auto& Cars : cars)
    {
        if (!Cars->Setup())
        {
            return -1;
        }
    }
       

    //окошко
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        } 
        //ограничение краев
        if (avto->Get_x() >= x0-a/2)
        {
            avto->Set_x(x0 - a/2);
        }
        if (avto->Get_x() <= a/2)
        {
            avto->Set_x(a/2);
        }
        if (avto->Get_y() >= y0 - a )
        {
            avto->Set_y(y0 - a );
        }
        if (avto->Get_y() <= a )
        {
            avto->Set_y(a);
        }

        
        for (const auto& Cars: cars)
        {
            if (Cars != nullptr)
            {
                Cars->Move();
                if (Cars->Get_y() >= y0 + a1 / 2)
                {
                    Cars->Set_y(-a1/2);
                    Cars->setVelocity(rand() % 35 + 30);
                }                                   
            }
            if (!Cars->Setup())
            {
                delete Cars;
                window.close();
                return -1;
            }
        }
         
        window.clear();

        window.draw(background);

        if (avto != nullptr)
        {
            window.draw(*avto->Get());
        }
        for (const auto& Cars : cars)
            window.draw(*Cars->Get());

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {avto->Move(0, -1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {avto->Move(0, 1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {avto->Move(-1, 0); }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {avto->Move(1, 0); }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {avto->Move(0, -2);}
        window.display();

        std::this_thread::sleep_for(40ms);
    }
    for (const auto& Cars : cars)
        delete Cars;
    cars.clear();

    if (avto != nullptr)
    {
        delete avto;
    }

    return 0;
}