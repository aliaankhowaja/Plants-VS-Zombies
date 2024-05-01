#pragma once
#include<SFML/Graphics.hpp>
#include<string> 
using namespace std;
class Screen
{
protected:
	sf::RenderWindow *window;
	sf::Sprite background;
	sf::Texture bgTexture;
public:
	Screen();
	virtual string Update() = 0;
	virtual void Draw() const = 0;
	//void operator=(Screen& screen);
	//Screen(sf::RenderWindow* window, const sf::Sprite& background);
};

