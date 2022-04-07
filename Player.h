#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <Box2D/Box2D.h>
#include "Emitter.h"

class BulletController;

class Player
{
	sf::Image imageTank;
	sf::Texture textureTank;
	sf::Sprite spriteTank;
	b2PolygonShape shape;
	b2BodyDef bdef;
	b2Body* body;

	std::string nameTank;

	BulletController* bulletController;

	sf::Vector2f positionSpawn;

	sf::Vector2f position;
	int speed;
	float rotation;
	float speedRotate;

	int widthSpriteTank;
	int heightSpriteTank;

	bool move, dir, changeDir, shoot, shooting;

	int hitPoints;

	Emitter smokeTank;

	int button;
public:
	Player(sf::Vector2f _position, std::string _nameTank, int _button);
	void Update(float time, std::list<Player*> tanks);
	void Draw(sf::RenderWindow& w);
	void control();
	sf::Sprite getSprite();
	std::string getName();
	int getHitPoints();
	void setHitPoints(int points);
	int takeDamage(int damage, sf::Vector2f _position);
	void restart();
};

