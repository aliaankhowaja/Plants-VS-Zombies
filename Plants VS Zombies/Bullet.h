#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
private:
	sf::Clock clock;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture splats;
	int row, x, id, destroyedAnimation, damage;
	bool exists, destroyed;
public:
	static int bulletID;
	Bullet();
	Bullet(int x, int row);
	sf::Sprite& GetSprite() ;
	int GetRow() const;
	int GetX() const;
	int GetID() const;
	void Revive();
	void Hit();
	void SetPosition(int column, int  row);
	bool GetExists() const;
	static void SetID();
	int GetDamage() const;
	bool GetDestroyed() const;
	bool Update();
	~Bullet();
};

//struct BulletContainer {
//	Bullet* bullet;
//	BulletContainer* nextBullet;
//	BulletContainer(int x,int row) {
//		bullet = new Bullet(x, row);
//		nextBullet = nullptr;
//	}
//	void NewBullet(int x, int row) {
//		nextBullet = new BulletContainer(x, row);
//	}
//
//};
