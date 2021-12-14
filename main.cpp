#include <SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <vector>
#include <iostream>
#include <Avto.hpp>
#include <Cars.hpp>
#include <windows.h>
#include <dos.h>
#include <string>

using namespace cr;
using namespace av;
using namespace std::chrono_literals;

int main()
{
    srand(0);
    float a = 260;
    float a1 = 188;
    float b1 = 250;
    int score = 0;
    sf::Texture texture;
    sf::Texture gameover;
    if (!texture.loadFromFile("Textures/doroga.jpg"))
    {
        std::cout << "File doroga.jpg not found!" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);

    float x0 = 1000, y0 = 1000;
    sf::RenderWindow window(sf::VideoMode(x0, y0), "Final!");

    int p = (x0 - a1) / 3;
    std::cout << p;

    if (!gameover.loadFromFile("Textures/gameover.png"))
    {
        std::cout << "Error with gameover texture!!!" << std::endl;
        return false;
    }
    sf::Sprite game_over(gameover);
    game_over.setPosition(180,300);

    sf::Font font;
    if (!font.loadFromFile("fonts/palai.ttf"))
    {
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);

    sf::Text Win;
    Win.setFont(font);
    Win.setCharacterSize(86);
    Win.setFillColor(sf::Color::Green);
    Win.setPosition(180,300);
    text.setString(std::string("You Win!"));

    sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2);

    //main avto
    Avto* avto = nullptr;
    avto=new Avto(x0 / 2, y0 - a, a);
    if (!avto->Setup())
    {
        delete avto;
        window.close();
        return -1;
    }
    //cars
    std::vector<Cars*> cars;
    for (int i = a1 * 0.9; i <= x0 - a1 / 2; i += a1 * 1.8)
    {
        cars.push_back(new Cars(i, 0, a1, b1, rand() % 15 + 10));
    }
        

    for (const auto& Cars : cars)
    {
        if (!Cars->Setup())
        {
            return -1;
        }
    }     
    //window open
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
        if (avto->Get_y() >= y0 - a)
        {
            avto->Set_y(y0 - a );
        }
        if (avto->Get_y() <= a/1.5)
        {
            avto->Set_y(a/1.5);
        }

        //столкновение
        /*for (const auto& Cars : cars)
        {
            int X = avto->Get_x();
            int Y = avto->Get_y();
     
            int x = Cars->Get_x();
            int y = Cars->Get_y();

            if ((abs(Y-y)<=240) && (abs(x-X)<=106) )
            {    
                text.setPosition(centerPos.x - text.getGlobalBounds().width / 2, centerPos.y - text.getGlobalBounds().height / 2);
                text.setString(std::string("Score ") + std::to_string(score));
                Sleep(500);
                window.draw(text);
                window.draw(game_over);
                window.display();
                Sleep(2000);
                window.close();
            }  

        }*/

        //перемещение врага с конца в начало + очки
        for (int i=0;i<3;i++)
        {
            if (cars[i] != nullptr)
            {
                cars[i]->Move();
                if (cars[i]->Get_y() >= y0 + a1 / 2)
                {
                    score++;
                    cars[i]->Set_y(-b1 / 2);
                    cars[i]->Set_x(a1/2+i*p+rand() % p - a1/2);
                        
                    if (score >= 20)
                    {
                        cars[i]->setVelocity(rand() % 75 + 70);
                    }
                    else if(score<20)
                    {
                        cars[i]->setVelocity(rand() % 20+15);
                    }       
                    if(score>=100)
                    {
                        text.setPosition(centerPos.x - text.getGlobalBounds().width / 2, centerPos.y - text.getGlobalBounds().height / 2);
                        text.setString(std::string("Score ") + std::to_string(score));
                        text.setString(std::string("You Win!"));
                        Sleep(500);
                        window.draw(text);
                        window.draw(Win);
                        window.display();
                        Sleep(3000);
                        window.close();
                    }
                }                                                      
            }
            if (!cars[i]->Setup())
            {
                delete cars[i];
                window.close();
                return -1;
            }
        }
                 
        window.draw(background);
        for (const auto& Cars : cars)
                    window.draw(*Cars->Get());
       
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {avto->Move(0, -1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))|| (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {avto->Move(0, 1);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {avto->Move(-1, 0);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {avto->Move(1, 0);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {avto->Move(0, -2);}
         
        if (avto != nullptr)
        {
            window.draw(*avto->Get());
        } 
        
        text.setString(std::string("Score ") + std::to_string(score));
        window.draw(text);

        window.display();
        
        window.clear();
       
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