#pragma once
#include<SFML/Graphics.hpp>
class Sun { 
private:
	const int width, height;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock clock;
	int x, y, destinationY;
	int animation;
	bool exists;
public:
	Sun();
	bool Clicked(int mouseX, int mouseY);
	void Update();
	sf::Sprite& GetSprite();
	void SetPosition(int x, int y, int destinationY);
	bool GetExists() const;
	void SetExists(bool exists);
};

