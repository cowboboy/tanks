#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string f, float m_speedRotate, float m_speedMovement, float speedRotateTurret, float x, float y);
	sf::Vector2f getCoords();
	void setAngle(float angle);
	sf::Sprite getSprite();
	sf::Sprite getSpriteTurret();
	void Update(float time);
	void rotateTurret();
	void Control(sf::RenderWindow& w);
	bool m_moveForward, m_moveBack, m_rotateRight, m_rotateLeft;
private:
	float m_speedRotate, m_speedRotateTurret, m_speedMovement, m_anglePlayer, m_angleTargetTurret, m_angleTurret;
	sf::Vector2f m_coords, m_targetPos;
	sf::Image m_imagePlayer;
	sf::Texture m_texturePlayer;
	sf::Sprite m_spritePlayer;
	sf::Sprite m_spriteTurret;
};

