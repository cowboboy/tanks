#include "FPS.h"

FPS::FPS() : fps(0), frames(0), timer(0)
{
}

void FPS::Update(float gameTime)
{
	timer += gameTime;
	if (timer >= 1.f) {
		timer = 0;
		fps = frames;
		frames = 0;
	}
	++frames;
}

int FPS::getFPS()
{
	return fps;
}
