#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"

class Bullet {
	sf::Image imageBullet;
	sf::Texture textureBullet;
	sf::Sprite spriteBullet;
	sf::Vector2f position;

	std::string name;

	sf::Image imageExplosion;
	sf::Texture textureExplosion;
	sf::Sprite spriteExplosion;
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
public:
	Bullet();
	void Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool shoot);
	void Draw(sf::RenderWindow& w);
};



