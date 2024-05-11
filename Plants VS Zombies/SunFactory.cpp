#include "SunFactory.h"

SunFactory::SunFactory(sf::RenderWindow* window)
{
	for (int i = 0; i < 5; i++) {
		suns[i] = new Sun();
	}
	this->window = window;
}

void SunFactory::Update()
{
	for (int i = 0; i < 5; i++) {
		if (!(suns[i]->GetExists())) continue;
		suns[i]->Update();
	}
}

int SunFactory::AddSuns(int mouseX, int mouseY)
{
	for (int i = 0; i < 5; i++) {
		if (!(suns[i]->GetExists())) continue;
		if (suns[i]->Clicked(mouseX, mouseY)) return 25;
	}
	return 0;
}

void SunFactory::NewSun()
{
	for (int i = 0; i < 5; i++) {
		if (suns[i]->GetExists()) continue;
		suns[i]->SetPosition(300 + rand() % 500, -78, 120 + rand() % 300);
		suns[i]->SetExists(true);
		return;
	}
	suns[0]->SetPosition(300 + rand() % 500, -78, 120 + rand() % 300);
	suns[0]->SetExists(true);
}

void SunFactory::NewSun(int column, int row)
{
	for (int i = 0; i < 5; i++) {
		if (suns[i]->GetExists()) continue;
		suns[i]->SetPosition(243 + column * 80, 80 + row * 100, 95 + row * 100);
		suns[i]->SetExists(true);
		return;
	}
	suns[0]->SetPosition(243 + column * 80, 80 + row * 100, 95 + row * 100);
	suns[0]->SetExists(true);
}

void SunFactory::Draw() const
{
	for (int i = 0; i < 5; i++) {
		if (!(suns[i]->GetExists())) continue;
		window->draw(suns[i]->GetSprite());
	}
}
