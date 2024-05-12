#include "FootballZombie.h"
FootballZombie::FootballZombie(int row) {
    name = "dancing zombie";
    health = 500;
    this->row = row;
    texture.loadFromFile("Resources/Images/zombiesd/football_zombie.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, 70.5, 70, 70));


    speed = 0.0001;
    sprite.setPosition(x, row * 144);
    moving = true;
}
void FootballZombie::Update() {
    if (moving) {
        texture.loadFromFile("Resources/Images/zombiesd/football_zombie.png");
        sf::IntRect source(0, 70.5, 64, 70.5);
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

        // Update sprite position
        sprite.setPosition(this->x -= 0.05f * speed, row);
    }
}


void FootballZombie::Act() {

}
//void FootballZombie::GetDps()
//{
//}