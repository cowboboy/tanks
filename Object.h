#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	sf::Image imageObject1;
	sf::Texture textureObject1;
	sf::Image imageObject2;
	sf::Texture textureObject2;
	sf::Sprite spriteObject;

	std::string nameObject;

	sf::Vector2f position;

	bool life;

	Object(sf::Image _imageObject1, sf::Image _imageObject2, sf::Vector2f _position, std::string _nameObject);
	virtual void reObject();
	void Update(float gameTime);
	virtual void Draw(sf::RenderWindow& w);
};

