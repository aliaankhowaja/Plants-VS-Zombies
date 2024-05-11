#include "SimpleZombie.h"
SimpleZombie::SimpleZombie(int row) {
	name = "SimpleZombie";
	health = 500;
    this->row = row;
	//dps = 50;
	texture.loadFromFile("Resources/Images/zombiesd/normalZombie.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 144, 144));
	speed = 0.0001;
	sprite.setPosition(x, row * 144);
	moving = true;
}

void SimpleZombie::Update()//animations
{
    if (moving) {
        texture.loadFromFile("Resources/Images/zombiesd/normalZombie.png");
        sf::IntRect source(0, 0, 66, 144);
        sprite.setTexture(texture);
        sprite.setTextureRect(source);

        static float elapsedTime = 0.0f; // Track elapsed time
        static int frameIndex = 0; // Track current frame index

        elapsedTime += clock.restart().asSeconds(); // Update elapsed time

        if (elapsedTime > 0.1f) { // Check if it's time to update frame
            ++frameIndex; // Move to the next frame
            if (frameIndex * 66 >= 396) // Check if we reached the end of the sprite sheet
                frameIndex = 0; // Reset frame index to start from the beginning
            source.left = frameIndex * 66; // Update the source rectangle left position

            sprite.setTextureRect(source); // Apply the updated source rectangle to the sprite
            elapsedTime = 0.0f; // Reset elapsed time for the next frame
        }

        sprite.setPosition(this->x -= 0.05f * speed, row); // Update sprite position
    }




	
}

//void SimpleZombie::GetDps()
//{
//}

void SimpleZombie::Act()
{
}
