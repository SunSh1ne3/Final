#include <SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <vector>
#include <iostream>
#include <Avto.hpp>

using namespace av;
using namespace std::chrono_literals;

int main()
{
    float a = 300;
    sf::Texture texture;
    if (!texture.loadFromFile("doroga.png"))
    {
        std::cout << "File doroga.png not found!" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);

    float x0 = 1500, y0 = 1080;
    sf::RenderWindow window(sf::VideoMode(x0, y0), "Final!");
    Avto* avto = nullptr;
    avto=new Avto(x0 / 2, y0 - 2 * a, a);
    if (!avto->Setup())
    {
        delete avto;
        window.close();
        return -1;
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
        if (avto->Get_x() >= x0-a/3)
        {
            avto->Set_x(x0 - a / 3);
        }
        if (avto->Get_x() <= a / 2)
        {
            avto->Set_x(a / 2);
        }
        if (avto->Get_y() >= y0 - a )
        {
            avto->Set_y(y0 - a );
        }
        if (avto->Get_y() <= a )
        {
            avto->Set_y(a );
        }

        window.clear();

        window.draw(background);
        if (avto != nullptr)
        {
            window.draw(*avto->Get());
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::W))){ avto->Move(0, -1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) { avto->Move(0, 1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) { avto->Move(-1, 0); }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) { avto->Move(1, 0); }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) { avto->Move(0, -2); }
        window.display();

        std::this_thread::sleep_for(40ms);
    }
    if (avto != nullptr)
    {
        delete avto;
    }

    return 0;
}