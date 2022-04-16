#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include <iostream>


class BulletController
{
	sf::Image imageBullet;
	sf::Texture textureBullet;
	sf::Sprite spriteBullet;

	sf::Image imageExplosion;
	sf::Texture textureExplosion;
	sf::Sprite spriteExplosion;

	std::string nameTank;

	std::list<Bullet> bullets;

	bool shoot;
	float recharge;
	float timer;
public:
	BulletController(std::string _nameTank);
	void Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool _shoot, std::list<Player*> tanks,
		std::list<Object*> objects);
	void Draw(sf::RenderWindow& w);
};

