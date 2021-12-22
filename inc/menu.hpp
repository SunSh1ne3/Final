#pragma once
#include<SFML\Graphics.hpp>

namespace fc
{
	bool menu(sf::RenderWindow& window);	
	bool ReMenu(sf::RenderWindow& window, int& score);
	bool WinMenu(sf::RenderWindow& window);
}