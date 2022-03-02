#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string f, float m_speedRotate, float m_speedMovement, float speedRotate, float x, float y);
	sf::Vector2f getCoords();
	void setAngle(float angle);
	sf::Sprite getSprite();
	sf::Sprite getSpriteTurret();
	void Update(float time);
	void Control();
	bool m_move;
private:
	float m_speedRotate, m_speedRotateTurret, m_speedMovement, m_anglePlayer;
	sf::Vector2f m_coords;
	sf::Image m_imagePlayer;
	sf::Texture m_texturePlayer;
	sf::Sprite m_spritePlayer;
	sf::Sprite m_spriteTurret;
};

