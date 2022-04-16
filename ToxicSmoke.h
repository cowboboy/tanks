#pragma once
#include "Emitter.h"
#include "Config.h"

class ToxicSmoke : public Emitter
{
	int speedPropagation;
public:
	ToxicSmoke();
	void EngineSmoke(sf::Vector2f position);
};

