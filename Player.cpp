#include "Player.h"
#include <iostream>
#include "Config.h"
#include "Bullet.h"
#include <Box2D/Box2D.h>
#include "World.h"
#include "BulletController.h"

Player::Player(sf::Vector2f _position, std::string _nameTank, int _button)
{
	widthSpriteTank = 64;
	heightSpriteTank = 48;

	imageTank.loadFromFile("images/tank1.png");
	textureTank.loadFromImage(imageTank);
	spriteTank.setTexture(textureTank);
	spriteTank.setTextureRect(sf::IntRect(0, 0, widthSpriteTank, heightSpriteTank));
	spriteTank.setOrigin(widthSpriteTank / 2, heightSpriteTank / 2);

	//position = sf::Vector2f(200, 200);
	positionSpawn = _position;
	position = positionSpawn;
	speed = 10 * 2;
	rotation = 0;
	speedRotate = 10.f * 5;

	shape.SetAsBox(widthSpriteTank / (SCALE * 2), heightSpriteTank / (SCALE * 2));
	bdef.type = b2_dynamicBody;
	bdef.position.Set(position.x / SCALE, position.y / SCALE);
	body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 100);

	hitPoints = 100;

	move = false;
	dir = true;
	changeDir = true;
	shoot = false;
	shooting = true;

	nameTank = _nameTank;

	bulletController = new BulletController(nameTank);

	button = _button;
}

void Player::Update(float time, std::list<Player*> tanks)
{
	control();

	b2Vec2 pos;
	float angle;
	pos = body->GetPosition();
	angle = body->GetAngle();

	position.x = pos.x * SCALE;
	position.y = pos.y * SCALE;
	rotation = angle * RADTODEG;

	if (hitPoints <= 0) {
		spriteTank.setTextureRect(sf::IntRect(widthSpriteTank, 0, widthSpriteTank, heightSpriteTank));
		smokeTank.EngineSmoke(position);
		shooting = false;
	}
	else {
		spriteTank.setTextureRect(sf::IntRect(0, 0, widthSpriteTank, heightSpriteTank));
	}

	if (hitPoints >= 0 && dir && !move) {
		body->SetAngularVelocity(time * speedRotate);
	}
	else if (hitPoints >= 0 && !dir && !move) {
		body->SetAngularVelocity(-time * speedRotate);
	}
	else {
		body->SetAngularDamping(time * speedRotate);
	}

	if (hitPoints >= 0 && move) {
		body->SetAngularVelocity(0);
		body->SetLinearVelocity(b2Vec2(speed * 0.1 * cos(angle), speed * 0.1 * sin(angle)));
	} 
	else {
		body->SetLinearDamping(speed);
	}

	spriteTank.setPosition(pos.x * SCALE, pos.y * SCALE);
	spriteTank.setRotation(angle * RADTODEG);
	move = false;

	if (!shooting) shoot = false;
	bulletController->Update(time, position, rotation, shoot, tanks);
	shoot = false;

	smokeTank.Update(time * 1000);
}

void Player::control()
{
	switch (button) {
	case 0:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			move = true;
			if (hitPoints && changeDir) {
				dir = !dir;
				changeDir = false;
				shoot = !shoot;
			}
		}
		else {
			changeDir = true;
		}
		break;
	case 1:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			move = true;
			if (hitPoints && changeDir) {
				dir = !dir;
				changeDir = false;
				shoot = !shoot;
			}
		}
		else {
			changeDir = true;
		}
		break;
	case 2:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			move = true;
			if (hitPoints && changeDir) {
				dir = !dir;
				changeDir = false;
				shoot = !shoot;
			}
		}
		else {
			changeDir = true;
		}
		break;
	case 3:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			move = true;
			if (hitPoints && changeDir) {
				dir = !dir;
				changeDir = false;
				shoot = !shoot;
			}
		}
		else {
			changeDir = true;
		}
		break;
	}
}

sf::Sprite Player::getSprite()
{
	return spriteTank;
}

std::string Player::getName()
{
	return nameTank;
}

int Player::getHitPoints()
{
	return hitPoints;
}

void Player::setHitPoints(int points)
{
	hitPoints += points;
}

int Player::takeDamage(int damage, sf::Vector2f _position)
{
	if (abs(position.x - _position.x) < widthSpriteTank / 2 &&
		abs(position.y - _position.y) < widthSpriteTank / 2) {
		hitPoints -= damage;
		return 1;
	}
	return -1;
}

void Player::restart()
{
	position = positionSpawn;
	b2Vec2 pos;
	float angle = 0;
	pos.x = positionSpawn.x / SCALE;
	pos.y = positionSpawn.y / SCALE;
	body->SetTransform(pos, angle);
	hitPoints = 100;
	shooting = true;
}

void Player::Draw(sf::RenderWindow& w)
{
	spriteTank.setPosition(position);
	spriteTank.setRotation(rotation);
	bulletController->Draw(w);
	w.draw(spriteTank);
	smokeTank.Draw(w);
}
