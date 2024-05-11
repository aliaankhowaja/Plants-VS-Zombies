#include "Level.h"
#include <iostream>
using namespace std;



Level::Level()
{

    font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");
    sunDisplay.setFont(font);
    sunDisplay.setCharacterSize(40);
    sunDisplay.setPosition(120, 0);
    sunDisplay.setString("0");
    sunDisplay.setFillColor(sf::Color::Black);
    clock.restart();
    suns = 0;
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
    if ((int)clock.getElapsedTime().asSeconds() / 10) {
        sunFactory->NewSun();
        clock.restart();
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
    for (int i = 0; i < 6; i++) {
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
    for (int i = 0; i < 6; i++) {
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
