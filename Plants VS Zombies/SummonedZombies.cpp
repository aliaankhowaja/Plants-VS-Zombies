#include "SummonedZombies.h"

SummonedZombies::SummonedZombies(int x, int y)
{
	this->x = x - 15;
	this->row = y;
    health = 200;
	texture.loadFromFile("Resources/Images/zombiesd/NormalZombie.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 144, 144));
	speed = 0.0001;
	sprite.setPosition(x, row);
	moving = 1;
}

void SummonedZombies::Update()
{
    if (moving) {
        static int currentFrame = 0; // Keeps track of the current frame
        static float frameDuration = 0.08f; // Duration for each frame (adjust as needed)
        static float elapsedTime = 0.0f; // Elapsed time for current frame
        static sf::Clock movementClock;
        // Load texture for current frame
        string filename = "Resources/Images/zombiesd/NormalZombie/Zombie/Zombie_" + std::to_string(currentFrame) + ".png";
        texture.loadFromFile(filename);
        sprite.setTexture(texture);

        // Update frame based on elapsed time
        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= frameDuration) {
            // Move to the next frame
            currentFrame = (currentFrame + 1) % 21; // 21 frames in total (0 to 20)
            elapsedTime = 0.0f;
        }
        float deltaTime = movementClock.restart().asSeconds();
        float distance = 30.0f * deltaTime; // 30 pixels per second

        // Update sprite position
        sprite.move(-distance, 0); // Move left
        // Update sprite position

    }
    if (!moving) {
        static int currentFrame = 0; // Keeps track of the current frame
        static float frameDuration = 0.08f; // Duration for each frame (adjust as needed)
        static float elapsedTime = 0.0f; // Elapsed time for current frame

        // Load texture for current frame
        string filename = "Resources/Images/zombiesd/NormalZombie/ZombieAttack/ZombieAttack_" + std::to_string(currentFrame) + ".png";
        texture.loadFromFile(filename);
        sprite.setTexture(texture);

        // Update frame based on elapsed time
        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= frameDuration) {
            // Move to the next frame
            currentFrame = (currentFrame + 1) % 21; // 21 frames in total (0 to 20)
            elapsedTime = 0.0f;

        }
    }
}

void SummonedZombies::Act()
{

}


