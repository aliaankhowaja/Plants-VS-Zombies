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


	speed = 20;
	sprite.setPosition(x, row * 144);
	moving = true;
}
void DancingZombie::Act() {
    int random = rand() % 2; // Adjusted to 2 for two possible directions
    if (movementC.getElapsedTime().asSeconds() > 2.0f) {
        switch (random) {
        case 0: // Moving down

            sprite.move(0, 100);
            if (row < 200)
                row += 100;
            else {
                row -= 100;
                sprite.move(0, -100);
            }


            break; // Added break statement to prevent fall-through
        case 1: // Moving up
            sprite.move(0, -100);
            row -= 100;
            if (row > 450)
                row -= 100;
            else {
                row += 100;
                sprite.move(0, +100);
            }
            break; // Added break statement to prevent fall-through
        }
        movementC.restart();
    }
    ///summon();
}
void DancingZombie::summon()
{
    //if (SummonClock.getElapsedTime().asSeconds() > 10.0f) {
    //    
    //    //SUMMON
    //    ptr = new SummonedZombies(500, 200);
    //    SummonClock.restart();
    //}
}
void DancingZombie::Update() {
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
   
    ////ptr->Update();


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

        // Update sprite position
        sprite.setPosition(this->x -= 0.05f * speed, row);
    }
    Act();

}

//void DancingZombie::GetDps()
//{
//}