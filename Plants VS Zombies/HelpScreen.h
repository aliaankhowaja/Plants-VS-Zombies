#pragma once
#include"Screen.h"

class HelpScreen : public Screen
{
private:
	sf::Texture PaperTexture;
	sf::Sprite Paper;
	sf::Texture WritingTexture;
	sf::Sprite Writing;
	sf::Texture ButtonTexture;
	sf::Sprite Button;
	sf::Texture ButtonGlowTexture;
	sf::Sprite ButtonGLow;

public:
	HelpScreen(sf::RenderWindow* window);
	void Draw() const;
	string Update();
};

