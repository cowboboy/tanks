#include "Map.h"
#include <iostream>

void Map::randomTree()
{
	int randTree = rand() % 2;
	switch (randTree)
	{
	case 0:
		spriteTree.setTexture(textureTree1);
		break;
	case 1:
		spriteTree.setTexture(textureTree2);
		break;
	}
}

void Map::randomTwigs()
{
	int randTwigs = rand() % 2;
	switch (randTwigs)
	{
	case 0:
		spriteTwigs.setTexture(textureTwigs1);
		break;
	case 1:
		spriteTwigs.setTexture(textureTwigs2);
		break;
	}
}

Map::Map() : dot(sf::Vector2f(W / 2, H / 2))
{
	imageMap1.loadFromFile("images/dirt.png");
	imageMap2.loadFromFile("images/ground_06.png");
	imageMap3.loadFromFile("images/sand.png");
	textureMap1.loadFromImage(imageMap1);
	textureMap2.loadFromImage(imageMap2);
	textureMap3.loadFromImage(imageMap3);

	imageTree1.loadFromFile("images/treeBrown_small.png");
	textureTree1.loadFromImage(imageTree1);
	imageTree2.loadFromFile("images/treeGreen_small.png");
	textureTree2.loadFromImage(imageTree2);
	imageTwigs1.loadFromFile("images/treeBrown_twigs.png");
	textureTwigs1.loadFromImage(imageTwigs1);
	imageTwigs2.loadFromFile("images/treeGreen_twigs.png");
	textureTwigs2.loadFromImage(imageTwigs2);

	restartMap();
}

void Map::Update(float time, std::list<Player*> tanks)
{
	dot.Update(time, tanks, objects);
}

void Map::draw(sf::RenderWindow& w)
{
	int m = W / widthSpriteMap + 1;
	int n = H / widthSpriteMap + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			spriteMap.setPosition(j * widthSpriteMap, i * heightSpriteMap);
			w.draw(spriteMap);
		}
	}
	for (auto object : objects) {
		object->Draw(w);
	}
	dot.draw(w);
}

std::list<Object*>& Map::getObjects()
{
	return objects;
}

void Map::restartMap()
{
	int randMap = rand() % 3;
	switch (randMap) {
	case 0:
		spriteMap.setTexture(textureMap1);
		break;
	case 1:
		spriteMap.setTexture(textureMap2);
		break;
	case 2:
		spriteMap.setTexture(textureMap3);
		break;
	}
	widthSpriteMap = spriteMap.getLocalBounds().width;
	heightSpriteMap = spriteMap.getLocalBounds().height;
	for (int i = 0; i < 10; ++i) {
		objects.push_back(new TreeObject(imageTree1, imageTwigs1, sf::Vector2f(rand() % W, rand() % H), "tree"));
	}
}
