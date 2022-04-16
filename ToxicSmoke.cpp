#include "ToxicSmoke.h"

ToxicSmoke::ToxicSmoke()
{
	mainImage.loadFromFile("images/particleToxicSmoke.png");
	smokeImage.loadFromFile("images/particleToxicSmoke.png");
}

void ToxicSmoke::EngineSmoke(sf::Vector2f position)
{
	if (particles.size() < 1000) {
		position.x = rand() % (int)position.x;
		position.y = rand() % H;

		sf::Vector2f velocity = angleToVector2f(1.047 + 1.047 * rand() / (float)RAND_MAX,
			0.005f + 0.05f * rand() / (float)RAND_MAX);

		float angle = 6.28 * rand() / (float)RAND_MAX;
		float angleVel = -0.005f + 0.01f * rand() / (float)RAND_MAX;

		sf::Color color = sf::Color(63, 63, 63, 229);
		sf::Color colorVel = sf::Color(
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00025f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.00075f + 0.000015f * rand() / (float)RAND_MAX)
		);

		float size = 0.5f + 1.2f * rand() / (float)RAND_MAX;

		float lifeTime = 5000;

		float sizeVel = 0.00025f;

		ParticleGeneration(mainImage, position, velocity, angle, angleVel, size, sizeVel, color,
			colorVel, lifeTime);
		/*
		position.x += rand() % 2;
		position.y += -3 + rand() % 2;

		sf::Vector2f velocity2 = angleToVector2f(1.047 + 1.047 * rand() / (float)RAND_MAX, 0);

		float angle2 = 6.28 * rand() / (float)RAND_MAX;
		float angleVel2 = -0.005f + 0.01f * rand() / (float)RAND_MAX;

		sf::Color color2 = sf::Color(229, 102, 51, 229);
		sf::Color colorVel2 = sf::Color(
			255 * (-0.0009f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.0004f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.0002f + 0.000025f * rand() / (float)RAND_MAX),
			255 * (-0.001f + 0.00025f * rand() / (float)RAND_MAX)
		);

		float size2 = 0.3f + 0.7f * rand() / (float)RAND_MAX;

		float lifeTime2 = 500;

		float sizeVel2 = -0.00005f;

		ParticleGeneration(mainImage, position, velocity2, angle2, angleVel2, size2, sizeVel2, color2,
			colorVel2, lifeTime2); */
	}
}
