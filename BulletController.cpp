#include "BulletController.h"

BulletController::BulletController(std::string _nameTank)
{
	imageBullet.loadFromFile("images/bullet.png");
	textureBullet.loadFromImage(imageBullet);
	spriteBullet.setTexture(textureBullet);

	imageExplosion.loadFromFile("images/explosion.png");
	textureExplosion.loadFromImage(imageExplosion);
	spriteExplosion.setTexture(textureExplosion);

	nameTank = _nameTank;

	shoot = false;
	recharge = 1;
	timer = recharge;
}

void BulletController::Update(float gameTime, sf::Vector2f positionTank, float rotationGun, bool _shoot, std::list<Player*> tanks)
{
	if (timer > 0) {
		timer -= gameTime;
	}

	if (timer <= 0) {
		shoot = _shoot;
	}

	if (shoot && timer <= 0) {
		bullets.push_back(Bullet(spriteBullet, spriteExplosion, nameTank));
		timer = recharge;
	}

	for (auto bullet = bullets.begin(); bullet != bullets.end();)
	{
		bullet->Update(gameTime, positionTank, rotationGun, shoot, tanks);
		if (bullet->getDeleteBullet())
		{
			bullet = bullets.erase(bullet);
		}
		else
			++bullet;
	}
}

void BulletController::Draw(sf::RenderWindow& w)
{
	for (auto bullet : bullets) {
		bullet.Draw(w);
	}
}
