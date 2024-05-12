#include "AddPlayerBlock.h"
AddPlayerBlock::AddPlayerBlock(sf::RenderWindow* window) {
    this->window = window;
    bgTexture.loadFromFile("Resources/Images/titlescreen.jpg");
    background.setTexture(bgTexture);
    BlockTexture.loadFromFile("Resources/Images/playerBlock.png");
    Block.setTexture(BlockTexture);
    Block.setPosition(270, 80);

    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");

    Rename.setString("Rename");
    Rename.setFont(font);
    Rename.setCharacterSize(24);
    Rename.setFillColor(sf::Color::Cyan);
    Rename.setPosition(570, 442);

    Delete.setString("Delete");
    Delete.setFont(font);
    Delete.setCharacterSize(24);
    Delete.setFillColor(sf::Color::Cyan);
    Delete.setPosition(570, 490);

    OK.setString("OK");
    OK.setFont(font);
    OK.setCharacterSize(24);
    OK.setFillColor(sf::Color::Cyan);
    OK.setPosition(385, 442);

    Cancel.setString("Cancel");
    Cancel.setFont(font);
    Cancel.setCharacterSize(24);
    Cancel.setFillColor(sf::Color::Cyan);
    Cancel.setPosition(370, 490);
}

void AddPlayerBlock::Draw() const
{
    window->draw(background);
    window->draw(Block);
    window->draw(Rename);
    window->draw(Delete);
    window->draw(OK);
    window->draw(Cancel);
}

string AddPlayerBlock::Update()
{
    sf::Event e;
    while (window->pollEvent(e)) {
        if (e.type == sf::Event::MouseButtonPressed) {


        }
    }
    
    return "";
}
