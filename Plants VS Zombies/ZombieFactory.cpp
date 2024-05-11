#include "ZombieFactory.h"
ZombieFactory::ZombieFactory(sf::RenderWindow* window){
	//srand(time(0));
	this->window = window;
	for (int i = 0; i < 6; i++) {
		
		zombies[i] = new DancingZombie();
	}
}
void ZombieFactory::Draw() {

	for (int i = 0; i < 6; i++) {
		if (!zombies[i]) continue;
		zombies[i]->Update();
		window->draw(zombies[i]->GetSprite());
	}

}