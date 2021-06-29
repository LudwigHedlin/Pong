#include "Timer.h"

void Timer::deltatime()
{
	dt = time - timer.getElapsedTime().asSeconds();
	time = timer.getElapsedTime().asSeconds();
}