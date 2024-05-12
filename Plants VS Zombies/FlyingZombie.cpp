#include "FlyingZombie.h"
FlyingZombie::FlyingZombie(int row) {
    name = "dancing zombie";
    health = 200;
    this->row = row;
    texture.loadFromFile("Resources/Images/zombiesd/flying_zombie.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, 0, 35, 58));
    sprite.setScale(1.6,1.6);

    speed = 10;
    sprite.setPosition(x, 50 + row * 100);
    moving = true;
    ready = 0;
}
string FlyingZombie::Update() {
    if (!((int)clock.getElapsedTime().asMilliseconds() % 50) && moving) {
        sprite.setTextureRect(sf::IntRect(34 * animation, 0, 35, 58));
        animation++;
        if (animation == 8) animation = 0;
    }
    if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
    {
        x -= speed;
        sprite.setPosition(x, 50 + 100 * row); // Update sprite position
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
void FlyingZombie::Act() {

}
