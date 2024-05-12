#include "FootballZombie.h"
FootballZombie::FootballZombie(int row) {
    name = "dancing zombie";
    health = 600;
    this->row = row;
    texture.loadFromFile("Resources/Images/zombiesd/football_zombie.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, 70.5, 70, 70));
    sprite.setScale(1.6, 1.6);


    speed = 10;
    sprite.setPosition(x, 15 + row * 100);
    moving = true;
}
void FootballZombie::Act() {
    moving = 0;
}



string FootballZombie::Update() {
    if (!((int)clock.getElapsedTime().asMilliseconds() % 50) && moving) {
        sprite.setTextureRect(sf::IntRect(64 * animation, 70, 64, 70));
        animation++;
        if (animation == 8) animation = 0;
    }
    if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
    {
        x -= speed;
        sprite.setPosition(x, 15 + 100 * row); // Update sprite position
        clock.restart();
    }
    if ((int)clock.getElapsedTime().asSeconds() / 1 && !moving) // add in other zombies
    {
        clock.restart();
        return "eating";
    }
    if (x > 160) {
        return "";
    }
    else
        return "reached";

}