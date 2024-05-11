#include "DancingZombie.h"
DancingZombie::DancingZombie() {
	name = "dancing zombie";
	health = 500;
	dps = 50;
	ZombieTexture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
	ZombieSprite.setTexture(ZombieTexture);

	ZombieSprite.setTextureRect(sf::IntRect(0, 0, 58, 74));


	speed = 0.0001;
	ZombieSprite.setPosition(startPos, SpawnRow * 144);
	moving = true;
}
void DancingZombie::Update() {
    if (moving) {
        ZombieTexture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
        sf::IntRect source(0, 0, 58, 74);
        ZombieSprite.setTexture(ZombieTexture);
        ZombieSprite.setTextureRect(source);
        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (source.left < 300)
                source.left += 50;
            else
                source.left = 0;
            clock.restart();
        }

       
           
        

        ZombieSprite.setPosition(this->startPos -= 0.05f * speed, row); // Update sprite position
    }
}
void DancingZombie::Act() {

}
void DancingZombie::GetDps()
{
}