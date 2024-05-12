#include "Level.h"
#include <iostream>
using namespace std;



Level::Level() : maxSpawnInterval(5), minSpawnInterval(5)
{
    progressBarFillTexture.loadFromFile("Resources/Images/ProgressBarFilled.png");
    progressBarFill.setTexture(progressBarFillTexture);
    progressBarFill.setScale(1.2, 1.2);
    progressBarFill.setPosition(700, 10);

    progressBarTexture.loadFromFile("Resources/Images/ProgressBar.png");
    progressBar.setTexture(progressBarTexture);
    progressBar.setScale(1.2, 1.2);
    progressBar.setPosition(700, 9);


    something = true;
    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
    sunDisplay.setFont(font);
    sunDisplay.setCharacterSize(40);
    sunDisplay.setPosition(120, 0);
    sunDisplay.setString("0");
    sunDisplay.setFillColor(sf::Color::Black);
    sunClock.restart();
    zombieClock.restart();
    suns = 100;
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
            //bullets[i][j]->SetExists(false);
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

void Level::DrawPlants() const
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue;
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
            if (plants[i][j]->GetHealth() <= 0) {
                delete plants[i][j];
                plants[i][j] = nullptr;
                /*for (int k = 0; k < 10; k++) {
                    zombies[i][k]->Move();
                }*/
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
            if (plants[i][j]->GetName() == "PeaShooter")
                //cout << 
                if (plants[i][j]->Act())
                {
                    NewBullet(j, i);
                    //cout << "Ds";
                }
        }
    }
}

void Level::GenerateSuns()
{
    if ((int)sunClock.getElapsedTime().asSeconds() / 4) {
        sunFactory->NewSun();
        sunClock.restart();
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!plants[i][j]) continue;
            if (plants[i][j]->GetName() == "SunFlower")
                //cout << 
                if (plants[i][j]->Act())
                {
                    sunFactory->NewSun(j, i);
                    //cout << "Ds";
                }
        }
    }
}

void Level::GenerateZombies()
{

    float spawnInterval = maxSpawnInterval - (maxSpawnInterval - minSpawnInterval) * (progress / 100.0f);
    //cout << spawnInterval << " " << zombieClock.getElapsedTime().asSeconds() << endl;
    // Check if it's time to generate a new zombie and if the zombie count is less than 10
    if (zombieClock.getElapsedTime().asSeconds() >= spawnInterval && generatedZombies < maxZombies) {
        // Generate a new zombie
        //zombies.push_back(Zombie(/* pass necessary parameters */));
        generatedZombies++; // Increment the zombie count
        // Increase progress when each zombie is created
        if (progress > 100.0f) {
            progress = 100.0f; // Ensure progress doesn't exceed 100
        }
        zombieClock.restart();
        // Print debug message (optional)
        //std::cout << "Zombie generated! Total zombies: " << generatedZombies << ", Progress: " << progress << std::endl;
        Zombie* zombie = zombieFactory->NewZombie(1);
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
    //TODO: Draw the zombies in game window. Check GenerateBullets() for reference
    //this logic works i believe
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (!zombies[i][j])continue;
            window->draw(zombies[i][j]->GetSprite());
        }
    }
}

void Level::UpdateZombies()
{
    //TODO: Draw the zombies in game window. Check UpdateBullets() for reference
    //this logic works i believe
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 10; j++) {

            if (!zombies[i][j]) continue;
            //cout<< zombies[i][j]->Update();
            int zombieX = zombies[i][j]->GetX();
            int zombieCol = (zombieX-135) / 80;
            //cout << zombieCol << endl;
            string out = zombies[i][j]->Update();
            if (out=="reached") {
                lawnMovers[i]->Use();
            }
            if (zombieCol >= columns) break;
            if (!(plants[i][zombieCol]))
            {
                zombies[i][j]->Move();
                continue;
            }

            //cout << "fd";
            zombies[i][j]->Act();
            if (out == "eating") {
                //cout << out<<endl;
                plants[i][zombieCol]->GetDamage();
            }
        }
        
    }
   
}
void Level::killZombies() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (lawnMovers[i]->GetUsed() && zombies[i][j] != nullptr) {
                if ((lawnMovers[i]->GetX() - 80) >= (zombies[i][j]->GetX())) {
                    delete zombies[i][j];
                    zombies[i][j] = NULL;
                }
            }
        }
    }
}



void Level::NewBullet(int column, int row)
{
    for (int i = 0; i < 20; i++) {
        if ((bullets[row][i]->GetExists()))continue;
        bullets[row][i]->Revive();
        bullets[row][i]->SetPosition(column, row);
        break;
    }
    //if (!bullets[row]) {
    //    bullets[row] = new BulletContainer(x, row);
    //} else {
    //    BulletContainer* nextBullet = bullets[row];
    //    while ((nextBullet->nextBullet)) {
    //        nextBullet = nextBullet->nextBullet;
    //    }
    //    nextBullet->NewBullet(x, row);
    //}
}

void Level::DrawBullets() const{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 20; j++) {
            if (!(bullets[i][j]->GetExists())) continue;
            window->draw(bullets[i][j]->GetSprite());
            
            //bullets[i][j].SetExists(true);
            //bullets[i] [j].SetPosition(column, row);
        }
    }
    //BulletContainer* nextBullet;
    //for (int i = 0; i < rows; i++) {
    //    if (!bullets[i]) continue;
    //    nextBullet = bullets[i];
    //    while (nextBullet) {
    //        window->draw(nextBullet->bullet->GetSprite());
    //        nextBullet = nextBullet->nextBullet;
    //    }
    //}
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
                if (!(bullet->GetDestroyed()) && (bullet->GetX() - 80) > zombie->GetX())
                {
                    bullet->Hit();
                    
                    zombie->GetDamage(bullet->GetDamage());
                    if (zombie->GetHealth() <= 0) {
                        delete zombie;
                        zombies[i][k] = nullptr;
                        zombieRows[i]--;
                        progress += 100 / maxZombies;
                    }
                    break;
                }
            }
            //bullets[i][j].SetExists(true);
            //bullets[i] [j].SetPosition(column, row);
        }
    }
    //BulletContainer* nextBullet;
    //BulletContainer* prevBullet;
    //bool first = true;
    //for (int i = 0; i < rows; i++) {
    //    if (!bullets[i]) continue;
    //    nextBullet = bullets[i];
    //    
    //    while (nextBullet) {
    //        cout << nextBullet->bullet->GetID() << "->";
    //        prevBullet = nextBullet;
    //        if(!nextBullet->bullet->Update()) {
    //            if (first) {
    //                if (!(prevBullet->nextBullet)) {
    //                    delete prevBullet;
    //                    bullets[i] = nullptr;
    //                    break;
    //                }
    //                else {
    //                    bullets[i] = nextBullet->nextBullet;
    //                    delete nextBullet;
    //                    nextBullet = bullets[i];
    //                    continue;
    //                }
    //            }
    //            prevBullet->nextBullet = nextBullet->nextBullet;
    //            delete nextBullet;
    //            nextBullet = prevBullet->nextBullet;
    //        }
    //        if (nextBullet) {
    //            nextBullet = nextBullet->nextBullet;
    //        }
    //        first = false;
    //    }
    //    cout << endl;
    //}
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
