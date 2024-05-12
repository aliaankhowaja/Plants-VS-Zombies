#include "SimpleZombie.h"
SimpleZombie::SimpleZombie(int row) {
	name = "SimpleZombie";
	health = 150;
    this->row = row;
	//dps = 50;
	texture.loadFromFile("Resources/Images/zombiesd/normalZombie.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 144, 144));
    speed = 5;
	sprite.setPosition(x, 15+row * 100);
	moving = 1;
}

//<<<<<<< HEAD
string SimpleZombie::Update()//animations
{
    if (!((int)clock.getElapsedTime().asMilliseconds() % 50) && moving) {
        sprite.setTextureRect(sf::IntRect(166 * animation, 0, 166, 144));
        animation++;
        if (animation == 22) animation = 0;
    }
    if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
    {
        x -= speed;
        sprite.setPosition(x, 15+ 100*row); // Update sprite position
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
//=======
//void SimpleZombie::Update() { 
//    if (moving) {
//        static int currentFrame = 0; // Keeps track of the current frame
//        static float frameDuration = 0.08f; // Duration for each frame (adjust as needed)
//        static float elapsedTime = 0.0f; // Elapsed time for current frame
//        static sf::Clock movementClock;
//        // Load texture for current frame
//        //string filename = "Resources/Images/zombiesd/NormalZombie/Zombie/Zombie_" + std::to_string(currentFrame) + ".png";
//        //texture.loadFromFile(filename);
//        sprite.setTexture(texture);
//
//        // Update frame based on elapsed time
//        elapsedTime += clock.restart().asSeconds();
//        if (elapsedTime >= frameDuration) {
//            // Move to the next frame
//            currentFrame = (currentFrame + 1) % 21; // 21 frames in total (0 to 20)
//            elapsedTime = 0.0f;
//        }
//        float deltaTime = movementClock.restart().asSeconds();
//        float distance = 30.0f * deltaTime; // 30 pixels per second
//
//        // Update sprite position
//        sprite.move(-distance, 0); // Move left
//        // Update sprite position
//    
////>>>>>>> 0a4c033753f2dd11df32aa7d186fe8b343b2658a
//    }
//    if (!moving) {
//        static int currentFrame = 0; // Keeps track of the current frame
//        static float frameDuration = 0.08f; // Duration for each frame (adjust as needed)
//        static float elapsedTime = 0.0f; // Elapsed time for current frame
//
//        // Load texture for current frame
//        string filename = "Resources/Images/zombiesd/NormalZombie/ZombieAttack/ZombieAttack_" + std::to_string(currentFrame) + ".png";
//        texture.loadFromFile(filename);
//        sprite.setTexture(texture);
//
//        // Update frame based on elapsed time
//        elapsedTime += clock.restart().asSeconds();
//        if (elapsedTime >= frameDuration) {
//            // Move to the next frame
//            currentFrame = (currentFrame + 1) % 21; // 21 frames in total (0 to 20)
//            elapsedTime = 0.0f;
//
//        }
//    }
//}


//void SimpleZombie::GetDps()
//{
//}

void SimpleZombie::Act()
{
    moving = 0;
}


