#include "FootballZombie.h"
FootballZombie::FootballZombie(int row) {
    name = "dancing zombie";
    health = 1200;
    this->row = row;
    texture.loadFromFile("Resources/Images/zombiesd/football_zombie.png");
    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, 70.5, 70, 70));
    sprite.setScale(1.6, 1.6);


    speed = 0.0001;
    sprite.setPosition(x, 15 + row * 100);
    moving = true;
}
void FootballZombie::Act() {
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
}



string FootballZombie::Update() {
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
        if ((int)clock.getElapsedTime().asSeconds() / 1 && moving)
        {
            x -= speed;
            sprite.setPosition(x, 15 + 100 * row); // Update sprite position
            clock.restart();
        }
    }
    Act();
    if (x > 180) {
        return "";
    }
    else
        return "reached";
}





//void FootballZombie::GetDps()
//{
//}