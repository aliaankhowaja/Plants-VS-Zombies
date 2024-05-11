#include "PausedGame.h"
PausedGame::PausedGame(sf::RenderWindow* window) {
    this->window = window;
    bgTexture.loadFromFile("Resources/Images/titlescreen.jpg");
    background.setTexture(bgTexture);
    BlockTexture.loadFromFile("Resources/Images/PusedGame.png");
    Block.setTexture(BlockTexture);
    Block.setPosition(250, 80);

    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
    GamePaused.setString("GAME PAUSED");
    GamePaused.setFont(font);
    GamePaused.setCharacterSize(50);
    GamePaused.setFillColor(sf::Color::Cyan);
    GamePaused.setPosition(342, 220);

    Restart.setString("RESTART");
    Restart.setFont(font);
    Restart.setCharacterSize(24);
    Restart.setFillColor(sf::Color::Cyan);
    Restart.setPosition(450, 375);

    MainMenu.setString("MAIN MENU");
    MainMenu.setFont(font);
    MainMenu.setCharacterSize(24);
    MainMenu.setFillColor(sf::Color::Cyan);
    MainMenu.setPosition(440, 420);

    BackToGame.setString("Back to Game");
    BackToGame.setFont(font);
    BackToGame.setCharacterSize(30);
    BackToGame.setFillColor(sf::Color::Cyan);
    BackToGame.setPosition(410, 500);
}

void PausedGame::Draw() const
{
    window->draw(background);
    window->draw(Block);
    window->draw(GamePaused);
    window->draw(Restart);
    window->draw(MainMenu);
    window->draw(BackToGame);
}

string PausedGame::Update()
{
    return "";
}
