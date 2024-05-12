#pragma once
#include "Screen.h"
class RewardScreen :
    public Screen
{
private:
    int reward;
    sf::Sprite Buttons[2];
    sf::Texture ButtonTexture;
    sf::Text Menu;
    sf::Text NextLvl;
    sf::Font font;
    sf::Text description;
    sf::Texture plantTexture;
    sf::Sprite plantSprite;
public:
    RewardScreen(int reward, sf::RenderWindow* window);
    
    void Draw() const;
    string Update();
};

