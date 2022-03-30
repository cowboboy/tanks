#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"
#include <Box2D/Box2D.h>

class Player : public Entity
{
public:
	int timer;
	Player(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR, int b);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	std::vector<Bullet*> bullets;
	void shoot();
private:
	bool m_move, m_dir;
	int m_changeDir;
	void control();
	bool collisionBorder(sf::Vector2f c);
	int button;
};

