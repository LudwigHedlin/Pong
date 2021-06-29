#include "PongBall.h"

void PongBall::update(real dt)
{
	position += velocity * dt;
	ball.setPosition(position.x - radius, position.y - radius);
}

void PongBall::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}