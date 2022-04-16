#include "Game1.h"

void Game1::startGame(int players)
{
	if (tanks.size() == 0) {
		switch (players) {
		case 2:
			tanks.push_back(new Player(imageTank1, sf::Vector2f(200, 400), "p1", 0));
			tanks.push_back(new Player(imageTank2, sf::Vector2f(1000, 400), "p2", 1));
			break;
		case 3:
			tanks.push_back(new Player(imageTank1, sf::Vector2f(600, 100), "p1", 0));
			tanks.push_back(new Player(imageTank2, sf::Vector2f(300, 700), "p2", 1));
			tanks.push_back(new Player(imageTank3, sf::Vector2f(900, 700), "p3", 2));
			break;
		case 4:
			tanks.push_back(new Player(imageTank1, sf::Vector2f(200, 100), "p1", 0));
			tanks.push_back(new Player(imageTank2, sf::Vector2f(1000, 100), "p2", 1));
			tanks.push_back(new Player(imageTank3, sf::Vector2f(200, 700), "p3", 2));
			tanks.push_back(new Player(imageTank4, sf::Vector2f(1000, 700), "p4", 3));
			break;
		}
		aliveTanks = tanks.size();
	}
	else {
		for (auto tank = tanks.begin(); tank != tanks.end();++tank)
		{
			(*tank)->restart();
		}
	}
}

void Game1::endGame()
{
}

void Game1::Update(float gameTime)
{
	map.Update(gameTime);
	if (!isGame && !menu) {
		menu = new Menu();
	}
	if (isGame && menu) {
		startGame(menu->isGame());
		delete menu;
		menu = nullptr;
	}
	if (menu) {
		menu->Update(gameTime, window);
		if (game && menu->isGame()) {
			isGame = menu->isGame();
			game = false;
		}
	}
	int k = 0;
	for (auto tank = tanks.begin(); tank != tanks.end();++tank)
	{
		if (aliveTanks == 1) {
			game = true;
			isGame = false;
			//(*tank)->restart();
		}
		else if ((*tank)->getHitPoints() >= 0){
			++k;
		}
		(*tank)->Update(gameTime, tanks, map.getObjects());
	}
	aliveTanks = k;
	fps.Update(gameTime);
}

void Game1::Draw()
{
	window.clear(sf::Color(128, 128, 128));
	map.draw(window);
	for (auto tank : tanks) {
		tank->Draw(window);
	}
	fps.Draw(window);
	if (menu) menu->Draw(window);
	window.display();
}

Game1::Game1() : window(sf::VideoMode(W, H), "Game")
{
	window.setFramerateLimit(60);
	elapsedSeconds = 0;

	imageMap.loadFromFile("images/map.png");
	textureMap.loadFromImage(imageMap);
	spriteMap.setTexture(textureMap);
	int widthSpriteMap = spriteMap.getLocalBounds().width;
	int heightSpriteMap = spriteMap.getLocalBounds().height;
	spriteMap.setOrigin(widthSpriteMap / 2, heightSpriteMap / 2);
	spriteMap.setPosition(W / 2, H / 2);
	spriteMap.scale(1.2f, 1.2f);

	game = true;
	isGame = false;
}

void Game1::Run()
{
	imageTank1.loadFromFile("images/tank_green1.png");
	imageTank2.loadFromFile("images/tank_yellow1.png");
	imageTank3.loadFromFile("images/tank_red1.png");
	imageTank4.loadFromFile("images/tank_blue1.png");

	while (window.isOpen())
	{
		float elapsedMilliseconds = clock.restart().asMilliseconds();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		World.Step(1 / 60.f, 8, 3);

		Update(elapsedMilliseconds);

		Draw();
	}
}
