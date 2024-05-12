#include "DancingZombie.h"
DancingZombie::DancingZombie(int row) {
	name = "dancing zombie";
	health = 500;
    this->row = row;
	//dps = 50;
	texture.loadFromFile("Resources/Images/zombiesd/normalZombie.png");
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(0, 0, 58, 74));


	speed = 20;
	sprite.setPosition(x, row * 144);
	moving = true;
}
void DancingZombie::Update() {
    if (moving) {
        texture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
        sf::IntRect source(0, 75, 62, 80);
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
void DancingZombie::Act() {

}
//void DancingZombie::GetDps()
//{
//}