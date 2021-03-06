#include <SFML\Graphics.hpp>
#include <Config.h>
#include <list>
#include <Object.h>
#include "TreeObject.h"
#include <Interface.h>
#include <Dot.h>

class Map {
	sf::Image imageMap1;
	sf::Image imageMap2;
	sf::Image imageMap3;
	sf::Texture textureMap1;
	sf::Texture textureMap2;
	sf::Texture textureMap3;
	sf::Sprite spriteMap;

	sf::Image imageTree1;
	sf::Texture textureTree1;
	sf::Image imageTree2;
	sf::Texture textureTree2;
	sf::Image imageTwigs1;
	sf::Texture textureTwigs1;
	sf::Image imageTwigs2;
	sf::Texture textureTwigs2;
	sf::Sprite spriteTree;
	sf::Sprite spriteTwigs;

	int widthSpriteMap, heightSpriteMap;

	Dot dot;

	void randomTree();
	void randomTwigs();

	std::list<Object*> objects;
public:
	Map();
	void Update(float time, std::list<Player*> tanks);
	void draw(sf::RenderWindow& w);
	std::list<Object*>& getObjects();
	void restartMap();
};
