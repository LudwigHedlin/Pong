#pragma once
#include "Header.h"
#include <SFML/System.hpp>
class Timer {
public:
	Timer()
	{
		time = timer.getElapsedTime().asSeconds();
	}
	void deltatime();

	real dt;

private:
	sf::Clock timer;
	real time;
	
};

