#include <SFML\Graphics.hpp>
class Map {
	sf::Image map_image;
	sf::Texture map;
	sf::Sprite s_map;
	int W, H;
public:
	Map(std::string f, int w, int h);
	void Update(float time);
	void draw(sf::RenderWindow& w);
	std::string clock(int time);
};
