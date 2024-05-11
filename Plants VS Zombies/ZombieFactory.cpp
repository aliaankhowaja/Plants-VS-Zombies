#include "ZombieFactory.h"
ZombieFactory::ZombieFactory(){
	srand(time(0));
	this->window = window;
	for (int i = 0; i < 6; i++) {
		
		zombies[i] = new DancingZombie();
	}
}
void ZombieFactory::Draw() {

	for (int i = 0; i < 6; i++) {
		zombies[i]->Update();
		window->draw(zombies[i]->GetSprite());
	}

}