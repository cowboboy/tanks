#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"
#include <Box2D/Box2D.h>
#include "Scene.h"
#include "Emitter.h"

class Player : public Entity
{
public:
	int timer;
	Player(std::string f, std::string n, sf::Vector2f c, Scene* lvl, float w, float h, int s, float sR, int b, sf::Image& _imageBullet);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
	//std::vector<Bullet*> bullets;
	//void shoot();
	Emitter* smoke;
private:
	Scene* m_lvl;
	std::string m_name;
	bool m_move, m_dir, m_shoot;
	int m_changeDir;
	void control();
	bool collisionBorder(sf::Vector2f c);

	Bullet bullet;
	
	int button;
};

