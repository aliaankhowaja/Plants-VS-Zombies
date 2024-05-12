#include "FlyingZombie.h"
FlyingZombie::FlyingZombie(int row) {
    name = "dancing zombie";
    health = 500;
    this->row = row;
    texture.loadFromFile("Resources/Images/zombiesd/flying_zombie.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, 0, 70, 70));
    sprite.setScale(1.6,1.6);

    speed = 0.000000001;
    sprite.setPosition(x, 15 + row * 100);
    moving = true;
}
void FlyingZombie::Update() {
    if (moving) {
        texture.loadFromFile("Resources/Images/zombiesd/flying_zombie.png");
        sf::IntRect source(0, 0, 36, 58);
        sprite.setTexture(texture);
        sprite.setTextureRect(source);

        // Adjust frame index based on elapsed time
        if (clock.getElapsedTime().asSeconds() > 0.80f) { // Adjust the time interval for smooth animation
            if (source.left < 488) {
                source.left += 64; // Move to the next frame
            }
            else {
                source.left = 0; // Restart animation
            }
            sprite.setTextureRect(source);
            clock.restart();
        }

        if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
        {
            x -= speed;
            sprite.setPosition(x, 15 + 100 * row); // Update sprite position
            clock.restart();
        }
    }
}
void FlyingZombie::Act() {

}
void FlyingZombie::GetDamage(int x)
{
    this->health -= x;
}
//void FlyingZombie::GetDps()
//{
//}