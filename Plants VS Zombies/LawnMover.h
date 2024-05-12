#pragma once
#include<SFML/Graphics.hpp>
class LawnMover
{
private:
	int x, row;
	sf::Sprite sprite;
	sf::Texture texture;
	bool used;
	bool exists;
	sf::Clock clock;
public:
	LawnMover(int row);
	void Update();
	sf::Sprite& GetSprite();
	void Use();
	int getX()const;
	bool GetExists() const;
	bool GetUsed() const;
};

