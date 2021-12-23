#include <menu.hpp>
#include<SFML\Graphics.hpp>
using namespace sf;
namespace fc
{
    
    bool menu(RenderWindow& window)
    {
        Texture NG, Ex, BG, AB,abot;
        NG.loadFromFile("Textures/NewGame.png");
        Ex.loadFromFile("Textures/Exit.png");
        BG.loadFromFile("Textures/fon.jpg");
        AB.loadFromFile("Textures/About.png");
        abot.loadFromFile("Textures/abot.png");

        Sprite NewGame(NG);
        NewGame.setPosition(420, 250);

        Sprite About(AB);
        About.setPosition(450, 310);

        Sprite Exit(Ex);
        Exit.setPosition(415, 370);

        Sprite Background(BG);
        Background.setPosition(0, 0);

        Sprite about(abot);


        bool isMenu = true;
        int menuNum = 0;
        while (isMenu)
        {
            NewGame.setColor(Color::Black);
            Exit.setColor(Color::Black);
            About.setColor(Color::Black);
            menuNum = 0;
            window.clear(Color::White);

            if (IntRect(420, 250, 200, 50).contains(Mouse::getPosition(window))) { NewGame.setColor(Color::Red); menuNum = 1; }
            if (IntRect(460, 310, 100, 50).contains(Mouse::getPosition(window))) { About.setColor(Color::Red); menuNum = 2; }
            if (IntRect(470, 370, 100, 50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Red); menuNum = 3; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {                                      
                    isMenu = false;     
                }

                if (menuNum == 2)
                { 
                    window.draw(about); 
                    window.display(); 
                    while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
                }

                if (menuNum == 3)
                {                   
                      
                    return false;  
                    isMenu = false;  
                    window.close();                
                                      
                }
            }

            window.draw(Background);
            window.draw(NewGame);
            window.draw(About);
            window.draw(Exit);

            window.display();
        }


    }

    bool ReMenu(RenderWindow & window, int& score)
    {
        Texture RE, Ex, BG, GO;
        RE.loadFromFile("Textures/Restart.png");
        Ex.loadFromFile("Textures/Exit.png");
        BG.loadFromFile("Textures/fon.jpg");
        GO.loadFromFile("Textures/gameover.png");

        sf::Text text;
        sf::Font font;
        font.loadFromFile("fonts/palai.ttf");
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::Yellow);
        text.setPosition(450,500);
        text.setString(std::string("Score ") + std::to_string(score));

        Sprite Restart(RE);
        Restart.setPosition(430, 350);

        Sprite Exit(Ex); 
        Exit.setPosition(425, 400);

        Sprite Gameover(GO);
        Gameover.setPosition(170, 0);
        
        Sprite Background(BG);
        Background.setPosition(0, 0); 

        bool isMenu = true;
        int menuNum = 0;

        while (isMenu)
        {
            Restart.setColor(Color::Black);
            Exit.setColor(Color::Black);
            menuNum = 0;
            window.clear(Color::White);

            if (IntRect(430, 350,200,50).contains(Mouse::getPosition(window))) { Restart.setColor(Color::Yellow); menuNum = 1; }
            if (IntRect(470, 390,100,50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Yellow); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {                    
                    return true;
                    isMenu = false;
                }

                if (menuNum == 2)
                {
                    return false;                   
                    window.close();
                    isMenu = false; 
                }
            }
            
            window.draw(Background);
            window.draw(Restart);
            window.draw(Exit);
            window.draw(Gameover);
            window.draw(text);

            window.display();
        }
          

    }

    bool WinMenu(sf::RenderWindow& window)
    {
        Texture RE, Ex, BG, WIN;
        RE.loadFromFile("Textures/Restart.png");
        Ex.loadFromFile("Textures/Exit.png");
        BG.loadFromFile("Textures/fon.jpg");
        WIN.loadFromFile("Textures/Win.png");

        Sprite Restart(RE);
        Restart.setPosition(430, 350);

        Sprite Exit(Ex);
        Exit.setPosition(425, 400);

        Sprite Win(WIN);
        Win.setPosition(200, 150);

        Sprite Background(BG);
        Background.setPosition(0, 0);

        bool isMenu = true;
        int menuNum = 0;

        while (isMenu)
        {
            Restart.setColor(Color::Black);
            Exit.setColor(Color::Black);
            menuNum = 0;
            window.clear(Color::White);

            if (IntRect(430, 350, 200, 50).contains(Mouse::getPosition(window))) { Restart.setColor(Color::Yellow); menuNum = 1; }
            if (IntRect(470, 390, 100, 50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Yellow); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {
                    isMenu = false;
                    return true;
                }

                if (menuNum == 2)
                {
                    isMenu = false;
                    return false;
                    window.close();
                }
            }

            window.draw(Background); 
            window.draw(Win);
            window.draw(Restart);
            window.draw(Exit);
           

            window.display();
        }
    }
}  