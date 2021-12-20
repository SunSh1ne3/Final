#include <menu.hpp>
#include<SFML\Graphics.hpp>

namespace fc
{
    using namespace sf;
    void menu(RenderWindow & window)
    {
        Texture NG, Ex, BG;
        NG.loadFromFile("Textures/NewGame.png");
        Ex.loadFromFile("Textures/Exit.png");
        BG.loadFromFile("Textures/fon.jpg");
        Sprite NewGame(NG), Exit(Ex), Background(BG);
        bool isMenu = 1;
        int menuNum = 0;
        NewGame.setPosition(50, 30);
        Exit.setPosition(50, 90);
        Background.setPosition(0, 0);

        while (isMenu)
        {
            NewGame.setColor(Color::Black);
            Exit.setColor(Color::Black);
            menuNum = 0;
            window.clear(Color::White);

            if (IntRect(50, 30,200,50).contains(Mouse::getPosition(window))) { NewGame.setColor(Color::Red); menuNum = 1; }
            if (IntRect(50, 90,100,50).contains(Mouse::getPosition(window))) { Exit.setColor(Color::Red); menuNum = 2; }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (menuNum == 1)
                {
                    window.close();
                    isMenu = false;
                }

                if (menuNum == 2)
                {
                    isMenu = false;
                }

            }

            window.draw(Background);
            window.draw(NewGame);
            window.draw(Exit);

            window.display();
        }
    }
}