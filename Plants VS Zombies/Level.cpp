#include "Level.h"
#include <iostream>
using namespace std;



Level::Level() : maxSpawnInterval(2), minSpawnInterval(1)
{
    something = true;
    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
    sunDisplay.setFont(font);
    sunDisplay.setCharacterSize(40);
    sunDisplay.setPosition(120, 0);
    sunDisplay.setString("0");
    sunDisplay.setFillColor(sf::Color::Black);
    sunClock.restart();
    zombieClock.restart();
    suns = 0;
    lvlProgress = 0;
    something = true;
    generatedZombies = 0;
    //////////MAX ZOMBIES/////////
    //maxZombies = 10;
   //grid = new Grid(window);
    //plantFactory = new PlantFactory(2, )
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
        progress += 100/maxZombies;
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
            break;
        }
    }


    /*if (something) {
        something = false;
    }*/
    //TODO: Generate new zombies. Check Generate suns for reference

    //this code is very problematic

  //TODO UPDATED: DO SOMETHING SUCH THAT A ZOMBIE CAN BE SEEN PLACED ON THE MAP (AGAR GALDI HO GAYE TO LINK ALL FILES) LIKE SPRITES CLICK KRNE PAR YOU GET SOME SCREEN
     

    /*int type=1;
    int time_1=0;*/

    //thought that maybe it doesnt work cuz zaida baar chalne k masla hai but this doesnt show the zombie spawning
    //dereferencing doesnt work either
   /* if (time_1 == 0) {
        zombies[5][8] = zombieFactory->NewZombie(type);
        time_1 = 1;
    }*/

    
    

    //ALI THIS CODE MAKES THE PROGRAM UNRESPONSIVE LIKE WHITE SCREEN AAJATI THA
   // zombies[0][0] = zombieFactory->NewZombie(type);
   // 
   // 
    //the progressive difficulty increase is working code
    // 
    // 
    //while (generatedZombies < maxZombies) {
    //    if (clock.getElapsedTime().asSeconds() == 10 - lvlProgress) {//faster the progress faster the zombie spawning
    //        type = rand() % 5;//random zombie type generated
    //        zombies[0][0]= zombieFactory->NewZombie(type);///type passed as argument to generate specific zombie
    //        generatedZombies++;//increment generated zombies
    //        lvlProgress += 2;//difficulty increases
    //        // i++;
    //        clock.restart();//again start generation time
    //    }
    //}
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
        for (int j = 0; j < columns; j++) {
            if (!zombies[i][j]) continue;
           cout<< zombies[i][j]->Update();
           if (!zombies[i][j]->Update().empty()) {
               lawnMovers[i]->Use();
              
           }
              

        }
        
    }
   
}
void Level::killZombies() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (lawnMovers[i]->GetUsed() && zombies[i][j] != nullptr) {
                if ((lawnMovers[i]->getX() - 80) >= (zombies[i][j]->getX())) {
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
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 20; j++) {
            if (!(bullets[i][j]->GetExists())) continue;
            bullets[i][j]->Update();
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
