#pragma once
#include "Header.h"
#include "Vec2.h"
#include <SFML/Graphics.hpp>
class PongBall {

public:

	PongBall() {};
	PongBall(Vec2 pos,real radius)
	{
		position = pos;
		this->radius = radius;
		ball.setRadius(radius);
		ball.setPosition(position.x - radius, position.y - radius);
	}

	void start() {};

	void draw(sf::RenderWindow& window);

	void update(real dt);

public:
	Vec2 position;
	Vec2 velocity = Vec2(-300,0);
	real radius;

	sf::CircleShape ball;
};

