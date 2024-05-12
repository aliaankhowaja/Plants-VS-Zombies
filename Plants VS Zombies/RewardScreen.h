#pragma once
#include "Screen.h"
class RewardScreen :
    public Screen
{
private:
    sf::Sprite Buttons[2];
    sf::Texture ButtonTexture;
    sf::Text Menu;
    sf::Text NextLvl;
    sf::Font font;
public:
    RewardScreen(sf::RenderWindow* window);
    
    void Draw() const;
    string Update();
};

