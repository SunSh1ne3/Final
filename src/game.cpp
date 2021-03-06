#include <SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <vector>
#include <iostream>
#include <Avto.hpp>
#include <Cars.hpp>
#include <menu.hpp>
#include <windows.h>
#include <dos.h>
#include <string>
#include <game.hpp>


using namespace cr;
using namespace av;
using namespace std::chrono_literals;

namespace gm
{
	bool game()
	{
        srand(time(NULL));
        int a = 280;
        int b = 243;
        int a1 = 153;
        float b1 = 250;
        int score = 0;
        int L = 0;
        int W = 0;
        sf::Texture texture;
        sf::Texture gameover;
        if (!texture.loadFromFile("Textures/doroga.jpg"))
        {
            std::cout << "File doroga.jpg not found!" << std::endl;
            return false;
        }
        sf::Sprite background(texture);

        

        float x0 = 1000, y0 = 1000;
        sf::RenderWindow window(sf::VideoMode(x0, y0), "Race");
        int p = (x0 - a1) / 3;

        sf::Image icon;
        if (!icon.loadFromFile("Textures/icon.png"))
        {
            return false;
        }
        window.setIcon(32, 24, icon.getPixelsPtr());

        fc::menu(window);       
        if (!fc::menu(window))
        {
            return false;
        }
  
       

        if (!gameover.loadFromFile("Textures/gameover.png"))
        {
            std::cout << "Error with gameover texture!!!" << std::endl;
            return false;
        }
        sf::Sprite game_over(gameover);
        game_over.setPosition(180, 300);

        sf::Font font;
        if (!font.loadFromFile("fonts/palai.ttf"))
        {
            std::cout << "ERROR: font was not loaded." << std::endl;
            return false;
        }

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        
        //main avto
        Avto* avto = nullptr;
        avto = new Avto(x0 / 2, y0 - a, a, b);
        if (!avto->Setup())
        {
            delete avto;
            window.close();
            return false;
        }
        //cars
        std::vector<Cars*> cars;
        for (int i = a1; i <= x0 - a1 / 2; i += 2.3 * a1)
        {
            cars.push_back(new Cars(i, 0, a1, b1, rand() % 15 + 10));
        }

        for (const auto& Cars : cars)
        {
            if (!Cars->Setup())
            {
                return false;
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
 
            //????????????
            for (const auto& Cars : cars)
            {
                int X = avto->Get_x();
                int Y = avto->Get_y();

                int x = Cars->Get_x();
                int y = Cars->Get_y();

                if ((abs(Y - y) <= 246) && (abs(x - X) <= 97))
                {
                    Cars->setVelocity(0);
                    L = 1;
                }
            }
            
            //??????????? ????? ? ????? ? ?????? + ????
            for (int i = 0; i < 3; i++)
            {
                if (cars[i] != nullptr)
                {
                    cars[i]->Move();
                    if (cars[i]->Get_y() >= y0 + a1)
                    {
                        score++;
                        cars[i]->Set_y(-b1 / 2);
                        cars[i]->Set_x((a1/4 + i * p )+(rand() % p + a1 / 4));

                        if (score < 20)
                        {
                            cars[i]->setVelocity(rand() % 20 + 15);
                        }
                        else if (score >= 20)
                        {
                            cars[i]->setVelocity(rand() % 25 + 20);
                        }
                        else if (score >= 50)
                        {
                            cars[i]->setVelocity(rand() % 30+25);
                        }
                        if (score >= 80)
                        {
                            cars[i]->setVelocity(0);
                            W = 1;
                        }
                    }
                }
                if (!cars[i]->Setup())
                {
                    delete cars[i];
                    window.close();
                    return false;
                }
            }

            window.draw(background);

            for (const auto& Cars : cars)
                window.draw(*Cars->Get());

            if (avto != nullptr)
            {
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) { avto->Move(0, -1); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) { avto->Move(0, 1); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) { avto->Move(-1, 0); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) { avto->Move(1, 0); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) { avto->Move(0, -2); }
            }

            //????????? main avto 
            if (avto != nullptr)
            {
                window.draw(*avto->Get());
            }

            //??????????? ?????
            if (avto->Get_x() >= x0 - 40)
            {
                avto->Set_x(x0 - 40);
            }
            if (avto->Get_x() <= a / 2)
            {
                avto->Set_x(a / 2);
            }
            if (avto->Get_y() >= y0 - b)
            {
                avto->Set_y(y0 - b);
            }
            if (avto->Get_y() <= b / 1.5)
            {
                avto->Set_y(b / 1.5);
            } 
            
            text.setString(std::string("Score ") + std::to_string(score));
            window.draw(text);

            window.display();

            window.clear();

            std::this_thread::sleep_for(40ms);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) { return true; }//???????? ???????? ????
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return false; }//???? Esc, ?? ??????? ?? ????

            if (L == 1)
            {
                fc::ReMenu(window, score);
                if (fc::ReMenu(window, score))
                {
                    L = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }

            if (W == 1)
            {
                fc::WinMenu(window);
                if (fc::WinMenu(window))
                {
                    W = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        for (const auto& Cars : cars)
            delete Cars;
        cars.clear();

        if (avto != nullptr)
        {
            delete avto;
        }
	}

    void ReGame()
    {
        if (game())
        {
            ReGame();
        }
    }
}