#include "DancingZombie.h"
DancingZombie::DancingZombie(int row) {
	name = "dancing zombie";
	health = 500;
    this->row = row;
	//dps = 50;
	texture.loadFromFile("Resources/Images/zombiesd/normalZombie.png");
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(0, 0, 58, 74));
    sprite.setScale(1.6, 1.6);

    //Summoned = NULL;
    ready = 0;
	speed = 20;
	sprite.setPosition(x, 15 + row * 100);
	moving = true;
}
void DancingZombie::Act() {
    int random = rand() % 2; // Adjusted to 2 for two possible directions
    if (movementC.getElapsedTime().asSeconds() > 2.0f) {
        switch (random) {
        case 0: // Moving down

            sprite.move(0, 100);
            if (row > 200)
                row += 100;
            else {
                row -= 100;
                sprite.move(0, -100);
            }


            break; // Added break statement to prevent fall-through
        case 1: // Moving up
            sprite.move(0, -100);
            row -= 100;
            if (row < 400)
                row -= 100;
            else {
                row += 100;
                sprite.move(0, +100);
            }
            break; // Added break statement to prevent fall-through
        }
        movementC.restart();
    }
    summon();
}
void DancingZombie::summon()
{
   
    if (SummonClock.getElapsedTime().asSeconds() > 2.0f) {
        ready = true;
        cout << ".";
       // cout << "ready true";// Set ready to true if more than 10 seconds have passed
    }

    //if (ready) {
    //    ready = false; // Set ready to false only when it's true
    //    //SummonClock.restart(); // Restart the clock
    //}
}




string DancingZombie::Update() {
    // Load texture only once (assuming it's constant)
    static sf::Texture texture; // Declare texture as static
    static bool textureLoaded = false; // Flag to track loading

    // Load texture on first call or if not already loaded
    if (!textureLoaded) {
        if (!texture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png")) {
            // Handle loading error
        }
        textureLoaded = true;
    }
    sprite.setTexture(texture); // Set texture outside the if block

    // Update animation based on fixed time step
   
    ////   ->Update();


    if (moving) {
        texture.loadFromFile("Resources/Images/zombiesd/dancing_zombie.png");
        sf::IntRect source(0, 75, 62, 80);
        sprite.setTexture(texture);
        sprite.setTextureRect(source);
       
        // Adjust frame index based on elapsed time
        if (clock.getElapsedTime().asSeconds() > 0.1) {
            // Adjust frame index
            if (source.left < 488) {
                source.left += 64;
            }
            else {
                source.left = 0;
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
    //Summoned->Update();
    Act();
    if (x > 180) {
        return "";
    }
    else
        return "reached";

}

//void DancingZombie::GetDps()
//{
//}