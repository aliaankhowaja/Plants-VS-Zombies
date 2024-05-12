#include "DancingZombie.h"
DancingZombie::DancingZombie(int row) {
	name = "dancing zombie";
	health = 250;
    this->row = row;
	//dps = 50;
	texture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(0, 0, 58, 74));
    sprite.setScale(1.6, 1.6);


	speed = 15;
	sprite.setPosition(x, 30 + row * 100);
	moving = true;
}
void DancingZombie::Act() {
    moving = 0;
}
void DancingZombie::summon()
{
}

string DancingZombie::Update() {
    if (!((int)clock.getElapsedTime().asMilliseconds() % 50) && moving) {
        sprite.setTextureRect(sf::IntRect(55 * animation, 75, 54, 80));
        animation++;
        if (animation == 6) animation = 0;
    }
    if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
    {
        x -= speed;
        sprite.setPosition(x, 30 + 100 * row); // Update sprite position
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
