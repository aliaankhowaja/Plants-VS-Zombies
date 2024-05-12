#include "ZombieFactory.h"
//ZombieFactory::ZombieFactory(sf::RenderWindow* window){
	//srand(time(0));
	//this->window = window;
	//for (int i = 0; i < 5; i++) {
	//	
	//	zombies[i] = new DancingZombie();
	//}
//}
ZombieFactory::ZombieFactory()
{
	//for (int i = 0; i < 5; i++) zombieRows[i] = 0;
	//progress = 0;
	//this->levelNum = levelNum;
}
Zombie* ZombieFactory::NewZombie(int zombieNum)
{
	int row = rand() % 5;
	cout << row;
	Zombie* zombie = nullptr;
	switch (zombieNum) {
	case 1:
		zombie = new SimpleZombie(row);
		break;
	case 2:
		zombie = new FootballZombie(row);
		break;
	case 3:
		zombie = new DancingZombie(row);
		break;
	case 4:
		zombie = new FlyingZombie(row);
		break;
	}
	//Zombie* zombie = new SimpleZombie(row);
	//zombieRows[row]++;
	return zombie;
}
//void ZombieFactory::Draw() {

	//for (int i = 0; i < 5; i++) {
	//	if (!zombies[i]) continue;
	//	//zombies[i]->Update();
	//	window->draw(zombies[i]->GetSprite());
	//}

//}
//void ZombieFactory::Update() {
	//for (int i = 0; i < 5; i++) {
	//if (!zombies[i]) continue;
	//	zombies[i]->Update();
	//	//window->draw(zombies[i]->GetSprite());
	//}
//}
