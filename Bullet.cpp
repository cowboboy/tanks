#include "Bullet.h"

Bullet::Bullet(sf::Sprite _spriteBullet, sf::Sprite _spriteExplosion, std::string _nameBullet)
{
	spriteBullet = _spriteBullet;
	spriteExplosion = _spriteExplosion;

	shooting = false;

	speed = 2;

	iCurrFrame = 0;
	jCurrFrame = 0;
	iFrames = spriteExplosion.getLocalBounds().width / widthFrame;
	jFrames = spriteExplosion.getLocalBounds().height / widthFrame;
	explode = false;
	animationTime = 0;  

	position = sf::Vector2f(0, 0);

	currTimeLife = timeLife;

	damage = 30;

	deleteBullet = false;

	nameBullet = _nameBullet;
}

void Bullet::Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool shoot, std::list<Player*> tanks)
{
	if (!shooting && !explode) {
		shooting = shoot;
		position = positionTank;
		rotation = rotationGun;
		currTimeLife = timeLife;
	}

	if (currTimeLife <= 0) {
		shooting = false;
		explode = true;
	}

	if (shooting) {
		position += speed * sf::Vector2f(cos(rotation * DEGTORAD), sin(rotation * DEGTORAD)) * gameTime * 100.f; 
	}

	if (explode) {
		if (animationTime > 0.1) {
			if ((iCurrFrame + 1) * (jCurrFrame + 1) == iFrames * jFrames) {
				iCurrFrame = 0;
				jCurrFrame = 0;
				explode = false;
				deleteBullet = true;
			}
			else {
				if (iCurrFrame < iFrames - 1) {
					++iCurrFrame;
				}
				else {
					iCurrFrame = 0;
					++jCurrFrame;
				}
			}
			animationTime = 0;
		}
		else {
			animationTime += gameTime;
		}
	}

	for (auto& tank : tanks) {
		if (shooting && nameBullet != tank->getName() && tank->takeDamage(damage, position) == 1) {
			shooting = false;
			explode = true;
		}
	}

	currTimeLife -= gameTime;
}
void Bullet::Draw(sf::RenderWindow& w)
{
	if (explode) {
		spriteExplosion.setPosition(position);
		spriteExplosion.setRotation(rotation);
		spriteExplosion.setTextureRect(sf::IntRect(iCurrFrame * widthFrame, jCurrFrame * widthFrame, widthFrame, widthFrame));
		spriteExplosion.setScale(0.8, 0.8);
		spriteExplosion.setOrigin(spriteExplosion.getLocalBounds().width / 2, spriteExplosion.getLocalBounds().height / 2);
		w.draw(spriteExplosion);
	}
	if (shooting) {
		spriteBullet.setPosition(position);
		spriteBullet.setRotation(rotation);
		spriteBullet.setScale(0.03, 0.03);
		spriteBullet.setOrigin(spriteBullet.getLocalBounds().width / 2, spriteBullet.getLocalBounds().height / 2);
		w.draw(spriteBullet);
	}
}

bool Bullet::getDeleteBullet()
{
	return deleteBullet;
}
