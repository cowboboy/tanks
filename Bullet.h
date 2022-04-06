#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Config.h"
#include "Player.h"

class Player;

class Bullet {
	sf::Sprite spriteBullet;

	sf::Sprite spriteExplosion;

	sf::Vector2f position;

	std::string nameBullet;

	const int widthFrame = 130;
	int iFrames, jFrames;
	int iCurrFrame, jCurrFrame;
	float animationTime;
	bool explode;

	float speed;

	float rotation;

	bool shooting;

	const float timeLife = 3;
	float currTimeLife;

	int damage;

	bool deleteBullet;
public:
	Bullet(sf::Sprite _spriteBullet, sf::Sprite _spriteExplosion, std::string _nameBullet);
	void Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool shoot, std::list<Player*> tanks);
	void Draw(sf::RenderWindow& w);
	bool getDeleteBullet();
};



