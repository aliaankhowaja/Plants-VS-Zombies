#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
struct GameObject {
	sf::Sprite sprite;
	sf::Texture texture;
	int x, y;
	//GameObject() {
	//	x = 0; y = 0;
	//	sprite = new sf::Sprite();
	//	texture = new sf::Texture();
	//}
	void SetTexture(string path) {
		texture.loadFromFile(path);
		sprite.setTexture(texture);
	}
	void SetTextureRect(int x, int y, int w, int h) {
		sprite.setTextureRect(sf::IntRect(x, y, w, h));
	}
	void SetPosition(int x, int y) {
		sprite.setPosition(x, y);
	}
};