#pragma once
#include<SFML/Graphics.hpp>
class Screen
{
	sf::RenderWindow *window;
	sf::Sprite background;
public:
	Screen();
	void Update();
	void Draw() const;
	//void operator=(Screen& screen);
	Screen(sf::RenderWindow* window, const sf::Sprite& background);
};

