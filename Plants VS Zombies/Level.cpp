#include "Level.h"
#include <iostream>
using namespace std;



Level::Level()
{
    //grid = new Grid(window);
    //plantFactory = new PlantFactory(2, )
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            plants[i][j] = nullptr;
        }
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
                    //NewBullet(290 + j * 80, i);
                    //cout << "Ds";
                }
        }
    }
}

void Level::NewBullet(int x, int row)
{
    if (!bullets[row]) {
        bullets[row] = new BulletContainer(x, row);
    } else {
        BulletContainer* nextBullet = bullets[row];
        while ((nextBullet->nextBullet)) {
            nextBullet = nextBullet->nextBullet;
        }
        nextBullet->NewBullet(x, row);
    }
}

void Level::DrawBullets()const {
    BulletContainer* nextBullet;
    for (int i = 0; i < rows; i++) {
        if (!bullets[i]) continue;
        nextBullet = bullets[i];
        while (nextBullet) {
            window->draw(nextBullet->bullet->GetSprite());
            nextBullet = nextBullet->nextBullet;
        }
    }
}
void Level::UpdateBullets() {
    
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