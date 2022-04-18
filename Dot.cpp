#include "Dot.h"

Dot::Dot(sf::Vector2f _position) : bombing("bombing")
{
	imageDot.loadFromFile("images/dot.png");
	textureDot.loadFromImage(imageDot);
	spriteDot.setTexture(textureDot);

	position = _position;
	rotation = 0;
	speedRotate = 10.f;

	widthSprite = spriteDot.getLocalBounds().width;
	heightSprite = spriteDot.getLocalBounds().height;

	shape.SetAsBox(widthSprite / (SCALE * 2), heightSprite / (SCALE * 2));
	bdef.type = b2_staticBody;
	bdef.position.Set(position.x / SCALE, position.y / SCALE);
	body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 100);
}

void Dot::Update(float gameTime, std::list<Player*> tanks, std::list<Object*> objects)
{
	rotation += speedRotate * gameTime * 0.001f;
	bombing.recharge = 100;
	bombing.Update(gameTime, position, rotation, true, tanks, objects);
}

void Dot::draw(sf::RenderWindow& w)
{
	spriteDot.setPosition(position);
	spriteDot.setOrigin(spriteDot.getLocalBounds().width / 2, spriteDot.getLocalBounds().height / 2);
	bombing.Draw(w);
	w.draw(spriteDot);
}
