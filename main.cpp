#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Config.h"
<<<<<<< HEAD
#include "map.h"
#include "view.h"
using namespace sf;
// Проверка GitHub
int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");
	Player p("tank.png", "player", 5.4, 3, 5, 0.1, 500, 500);
	view.reset(sf::FloatRect(0, 0, 640, 480));//размер "вида" камеры при создании объекта вида камеры. (потом можем менять как хотим) Что то типа инициализации.
=======
// РџСЂРѕРІРµСЂРєР° GitHub
int main() {
	sf::RenderWindow window(sf::VideoMode(W, H), "Game");
	Player p("tank.png", "player", sf::Vector2f(500, 500), 3, 0.5f, 2, 5.f);
	Enemy p2("tank.png", "enemy", sf::Vector2f(900, 200), 3, 0.5f, 2, 5.f);

>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782
	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate,offsetX = 0;
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/map.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом
	while (window.isOpen())
	{
		sf::Clock clock;
		int elapsedMilliseconds = clock.restart().asMicroseconds();

		p.control(window);
		p2.rotateTurret(p.getCoords());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
<<<<<<< HEAD
		for (int i = 0; i < frames; ++i) p.Update(elapsedMillisecondsExpected);

		std::cout << p.m_speedMovement << std::endl;
		
=======
		for (int i = 0; i < frames; ++i) {
			p.Update(elapsedMillisecondsExpected);
			p2.Update(elapsedMillisecondsExpected);
		}
>>>>>>> 32612ac126a4c8ad9c3432dd73d057c5921c3782

		
		window.clear();
		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 64, 64)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(128, 0, 64, 64));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 128, 64, 64));//если встретили символ 0, то рисуем 3й квадратик
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(64,0, 64, 64));

				s_map.setPosition(j * 64, i * 64);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);//рисуем квадратики на экран
			}
		p.draw(window);
		p2.draw(window);
		window.display();
	}
	return 0;
}
