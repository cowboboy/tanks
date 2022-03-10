#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;
void getplayercoordinateforview(sf::Vector2f c) { //функция для считывания координат игрока

	view.setCenter(c.x, c.y); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте

}

