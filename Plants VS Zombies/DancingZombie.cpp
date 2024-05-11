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
        //ZombieTexture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
        sf::IntRect source(0, 0, 58, 74);
        sprite.setTexture(texture);
        sprite.setTextureRect(source);
        if (clock.getElapsedTime().asSeconds() > 0.5f) {
            sprite.setPosition(this->x -= 0.5f * speed, row); // Update sprite position
            if (source.left < 300)
                source.left += 50;
            else
                source.left = 0;
            clock.restart();
        }
          
        //if ((int)clock.getElapsedTime().asSeconds() / 2)
    }
}
void DancingZombie::Act() {

}
//void DancingZombie::GetDps()
//{
//}