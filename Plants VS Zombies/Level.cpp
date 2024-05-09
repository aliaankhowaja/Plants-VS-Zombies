#include "Level.h"

Level::Level()
{
    //grid = new Grid(window);
    //plantFactory = new PlantFactory(2, )
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            plants[i][j] = nullptr;
        }
    }
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
