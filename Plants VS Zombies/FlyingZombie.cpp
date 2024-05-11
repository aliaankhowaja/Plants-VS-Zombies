#include "FlyingZombie.h"
FlyingZombie::FlyingZombie() {
    name = "dancing zombie";
    health = 500;
    dps = 50;
    ZombieTexture.loadFromFile("Resources/Images/zombiesd/flying_zombie.png");
    ZombieSprite.setTexture(ZombieTexture);

    ZombieSprite.setTextureRect(sf::IntRect(0, 0, 144, 144));


    speed = 0.0001;
    ZombieSprite.setPosition(startPos, SpawnRow * 144);
    moving = true;
}
void FlyingZombie::Update() {
    if (moving) {
        ZombieTexture.loadFromFile("Resources/Images/zombiesd/flying_zombie.png");
        sf::IntRect source(0, 0, 66, 144);
        ZombieSprite.setTexture(ZombieTexture);
        ZombieSprite.setTextureRect(source);

        static float elapsedTime = 0.0f; // Track elapsed time
        static int frameIndex = 0; // Track current frame index

        elapsedTime += clock.restart().asSeconds(); // Update elapsed time

        if (elapsedTime > 0.1f) { // Check if it's time to update frame
            ++frameIndex; // Move to the next frame
            if (frameIndex * 66 >= 396) // Check if we reached the end of the sprite sheet
                frameIndex = 0; // Reset frame index to start from the beginning
            source.left = frameIndex * 66; // Update the source rectangle left position

            ZombieSprite.setTextureRect(source); // Apply the updated source rectangle to the sprite
            elapsedTime = 0.0f; // Reset elapsed time for the next frame
        }

        ZombieSprite.setPosition(this->startPos -= 0.05f * speed, row); // Update sprite position
    }
}
void FlyingZombie::Act() {

}
void FlyingZombie::GetDps()
{
}