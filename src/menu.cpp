#include <menu.hpp>
#include<SFML\Graphics.hpp>

namespace fc
{
    using namespace sf;
    void menu(RenderWindow& window)
    {
        Texture NG, Ex, BG;
        NG.loadFromFile("Textures/NewGame.png");
        Ex.loadFromFile("Textures/Exit.png");
        BG.loadFromFile("Textures/fon.jpg");

        Sprite NewGame(NG);
        NewGame.setPosition(420, 250);

        Sprite Exit(Ex);
        Exit.setPosition(415, 310);

        Sprite Background(BG);
        Background.setPosition(0, 0);

        bool isMenu = true;
        int menuNum = 0;
        while (isMenu)
        {
            NewGame.setColor(Color::Black);
            Exit.setColor(Color::Black);
            menuNum = 0;
            window.clear(Color::White);

            if (IntRect(420, 250, 200, 50).contains(Mouse::getPosition(window))) { NewGame.setColor(Color::Red); menuNum = 1; }
            if (IntRect(445, 310, 100, 50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Red); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {
                    
                    isMenu = false;
                }

                if (menuNum == 2)
                {
                    window.close();
                    isMenu = false;
                }
            }

            window.draw(Background);
            window.draw(NewGame);
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
            if (IntRect(455, 390,100,50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Yellow); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {
                    isMenu = false; 
                    return true;
                }

                if (menuNum == 2)
                {
                    window.close();
                    isMenu = false;
                    return false;
                }
            }
            
            window.draw(Background);
            window.draw(Restart);
            window.draw(Exit);
            window.draw(Gameover);

            window.display();
        }
          

    }
}
    
    
    