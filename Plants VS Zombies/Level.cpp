#include "Level.h"
#include <iostream>
using namespace std;



Level::Level() : maxSpawnInterval(15), minSpawnInterval(5)
{
    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");

    gameOverTexture.loadFromFile("Resources/Images/gameOver.png");
    gameOver.setTexture(gameOverTexture);
    gameOver.setPosition(218, 66);

    BlockTexture.loadFromFile("Resources/Images/PusedGame.png");
    Block.setTexture(BlockTexture);
    Block.setPosition(250, 80);

    //font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
    GamePaused.setString("GAME PAUSED");
    GamePaused.setFont(font);
    GamePaused.setCharacterSize(50);
    GamePaused.setFillColor(sf::Color::Cyan);
    GamePaused.setPosition(342, 220);

    Restart.setString("RESTART");
    Restart.setFont(font);
    Restart.setCharacterSize(24);
    Restart.setFillColor(sf::Color::Cyan);
    Restart.setPosition(450, 375);

    MainMenu.setString("MAIN MENU");
    MainMenu.setFont(font);
    MainMenu.setCharacterSize(24);
    MainMenu.setFillColor(sf::Color::Cyan);
    MainMenu.setPosition(440, 420);

    BackToGame.setString("Back to Game");
    BackToGame.setFont(font);
    BackToGame.setCharacterSize(30);
    BackToGame.setFillColor(sf::Color::Cyan);
    BackToGame.setPosition(410, 500);
    
    pauseText.setFont(font);
    pauseText.setCharacterSize(23);
    pauseText.setPosition(920, 12);
    pauseText.setString("Pause");
    pauseText.setFillColor(sf::Color::White);

    pauseTexture.loadFromFile("Resources/Images/options_backtogamebutton0.png");
    pauseButton.setTexture(pauseTexture);
    pauseButton.setPosition(905, 7);
    pauseButton.setScale(0.25, 0.4);

    gamePaused = false;
    lives = 3;
    progressBarFillTexture.loadFromFile("Resources/Images/ProgressBarFilled.png");
    progressBarFill.setTexture(progressBarFillTexture);
    progressBarFill.setScale(1.2, 1.2);
    progressBarFill.setPosition(700, 10);

    progressBarTexture.loadFromFile("Resources/Images/ProgressBar.png");
    progressBar.setTexture(progressBarTexture);
    progressBar.setScale(1.2, 1.2);
    progressBar.setPosition(700, 9);

    brainsTexture.loadFromFile("Resources/Images/Brains.png");
    brains.setTexture(brainsTexture);
    brains.setPosition(500, 9);

    sunBankTexture.loadFromFile("Resources/Images/sunBank.png");
    sunBank.setTexture(sunBankTexture);
    sunBank.setPosition(120, 4);

    rewardTexture.loadFromFile("Resources/Images/cards.png");
    rewardSprite.setTexture(rewardTexture);

    something = true;
    sunDisplay.setFont(font);
    sunDisplay.setCharacterSize(40);
    sunDisplay.setPosition(175, 4);
    sunDisplay.setString("0");
    sunDisplay.setFillColor(sf::Color::Black);
    sunClock.restart();
    zombieClock.restart();
    suns = 0;
    lvlProgress = 0;
    something = true;
    generatedZombies = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            plants[i][j] = nullptr;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 20; j++) {
            bullets[i][j] = new Bullet();
        }
    }
    for (int i = 0; i < rows; i++) {
        lawnMovers[i] = new LawnMover(i);
    }
    
    for(int i = 0; i < rows; i++) zombieRows[i] = 0;
}

void Level::SetPlant(Plant* plant, int row, int column)
{
    plants[row][column] = plant;
}

Plant* Level::GetPlant(int row, int column)
{
    return plants[row][column];
}

void Level::DrawPlants() const // draw plants in window
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue; // if null then continue
            window->draw(plants[i][j]->GetSprite());
        }
    }
}

void Level::UpdatePlants()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue;
            plants[i][j]->Update();
            if (plants[i][j]->GetHealth() <= 0) { // if plant died 
                delete plants[i][j];
                plants[i][j] = nullptr;
            }
        }
    }
}

void Level::Shoot()
{
    for (int i = 0; i < rows; i++) {
        if (!zombieRows[i]) continue;
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue;
            if (plants[i][j]->GetName() == "PeaShooter") // if plant is peashooter
                if (plants[i][j]->Act()) // after 2 seconds
                {
                    NewBullet(j, i); //generate a bullet
                    //cout << "Ds";
                }
            if (plants[i][j]->GetName() == "CherryBomb")
                //cout << 
                if (plants[i][j]->Act())
                {
                    delete plants[i][j];
                    plants[i][j] = nullptr;
                }
        }
    }
}

void Level::GenerateSuns()
{

    
    if ((int)sunClock.getElapsedTime().asSeconds() / 10) { // every 10 seconds
        sunFactory->NewSun();
        sunClock.restart();
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue;
            if (plants[i][j]->GetName() == "SunFlower") // if sunflower
                if (plants[i][j]->Act()) // 10 sec interval
                {
                    sunFactory->NewSun(j, i);
                }
        }
    }
}

void Level::GenerateZombies()
{

    float spawnInterval = maxSpawnInterval - (maxSpawnInterval - minSpawnInterval) * (progress / 100.0f); // get the spawn interval
    if (zombieClock.getElapsedTime().asSeconds() >= spawnInterval && generatedZombies < maxZombies) {
        generatedZombies++; // Increment the zombie count
        //if (progress > 100.0f) {
        //    progress = 100.0f; // Ensure progress doesn't exceed 100
        //}
        zombieClock.restart();
        int type = rand() % 4 + 1; // get random zombie
        Zombie* zombie = nullptr;
        if (name == "BignnersGarden") { // if level 1
            zombie = zombieFactory->NewZombie(1); // generate normal zombie
        }
        else {
            zombie = zombieFactory->NewZombie(type);
        }
        int row = zombie->GetRow();
        for (int i = 0; i < 20; i++) {
            if (zombies[row][i]) continue;
            zombies[row][i] = zombie;
            zombieRows[row]++;
            break;
        }
    }
}

void Level::DrawZombies() const
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (!zombies[i][j])continue;
            window->draw(zombies[i][j]->GetSprite());
        }
    }
}

void Level::UpdateZombies()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 10; j++) {

            if (!zombies[i][j]) continue;
            //cout<< zombies[i][j]->Update();
            int zombieX = zombies[i][j]->GetX();
            int zombieCol = (zombieX-135) / 80;
            //cout << zombieCol << endl;
            string out = zombies[i][j]->Update();
            if (out=="reached" && !(lawnMovers[i]->GetUsed())) { // if reached and lawn mover present
                lawnMovers[i]->Use();
            }
            else if (out == "reached" && !(lawnMovers[i]->GetExists())) { // reached and lawn mover not present
                lives--;
                DeleteZombie(i, j);
            }
            if (zombieCol >= columns) break;
            if (!(plants[i][zombieCol]))
            {
                if(zombies[i][j])
                    zombies[i][j]->Move();
                continue;
            }
            zombies[i][j]->Act();
            if (out == "eating") {
                plants[i][zombieCol]->GetDamage();
            }
        }
        
    }
   
}
void Level::Draw() const
{
    window->draw(background);
    DrawPlants();
    DrawLawnMovers();
    plantFactory->Draw();
    window->draw(sunBank);
    window->draw(sunDisplay);
    if (progress >= 100)
        window->draw(rewardSprite);
    window->draw(progressBarFill);
    window->draw(progressBar);
    window->draw(brains);
    sunFactory->Draw();
    DrawZombies();
    DrawBullets();
}
void Level::killZombies() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (lawnMovers[i]->GetExists() && lawnMovers[i]->GetUsed() && zombies[i][j] != nullptr) {
                if ((lawnMovers[i]->GetX() - 80) >= (zombies[i][j]->GetX())) { // lawn mover hits zombie
                    DeleteZombie(i, j);
                }
            }
        }
    }
}

void Level::DeleteZombie(int i, int j) {
    progress += 100.0 / maxZombies;
    if (progress >= 100) rewardSprite.setPosition(zombies[i][j]->GetX(), 80 + i * 80); // last zombie
    delete zombies[i][j];
    zombies[i][j] = nullptr;
    zombieRows[i]--;
}


void Level::NewBullet(int column, int row)
{
    for (int i = 0; i < 20; i++) {
        if ((bullets[row][i]->GetExists()))continue;
        bullets[row][i]->Revive();
        bullets[row][i]->SetPosition(column, row);
        break;
    }
}

void Level::DrawBullets() const{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 20; j++) {
            if (!(bullets[i][j]->GetExists())) continue;
            window->draw(bullets[i][j]->GetSprite());
        }
    }
}
void Level::UpdateBullets() {
    Bullet* bullet;
    Zombie* zombie;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 20; j++) {
            bullet = bullets[i][j];
            if (!(bullet->GetExists())) continue;
            bullet->Update();
            for (int k = 0; k < 10; k++) {
                zombie = zombies[i][k];
                if (!zombie) continue;
                if (!(bullet->GetDestroyed()) && (bullet->GetX() - 80) > zombie->GetX()) // bullet hits zombie
                {
                    bullet->Hit();
                    
                    zombie->GetDamage(bullet->GetDamage());
                    if (zombie->GetHealth() <= 0) {
                        DeleteZombie(i, j);
                    }
                    break;
                }
            }
        }
    }
}

void Level::DrawLawnMovers() const
{
    for (int i = 0; i < rows; i++) {
        if (lawnMovers[i]->GetExists()) {
            window->draw(lawnMovers[i]->GetSprite());
        }
    }
}

void Level::UpdateLawnMovers()
{
    for (int i = 0; i < rows; i++) {
        if (lawnMovers[i]->GetUsed()) {
            lawnMovers[i]->Update();
        }
    }
}
