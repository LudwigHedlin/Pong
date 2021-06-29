#include "PongRect.h"

bool PongRect::isInside(Vec2& pos)
{
	bool isXInside = pos.x<position.x + width / 2 && pos.x > position.x - width / 2;
	bool isYInside = pos.y<position.y + height / 2 && pos.y > position.y - height / 2;
	return isXInside && isYInside;
}

bool PongRect::isCollision(PongBall& ball)
{
	Vec2 pos = ball.position;
	bool isRightOf = pos.x > position.x + width / 2;
	bool isLeftOf = pos.x < position.x - width / 2;
	bool isAbove = pos.y>position.y + height / 2;
	bool isBelow = pos.y < position.y - height / 2;
	Vec2 nearestPoint;
	if (isRightOf)
	{
		nearestPoint.x = position.x + width / 2;
	}
	else if (isLeftOf)
	{
		nearestPoint.x = position.x - width / 2;
	}
	else
	{
		nearestPoint.x = pos.x;
	}
	if (isAbove)
	{
		nearestPoint.y = position.y + height / 2;
	}
	else if (isBelow)
	{
		nearestPoint.y = position.y - height / 2;
	}
	else
	{
		nearestPoint.y = pos.y;
	}
	return (pos - nearestPoint).length() < ball.radius;
	
	
}

void PongRect::collision(PongBall& ball)
{
	if (ball.position.x > position.x + width / 2 || ball.position.x < position.x - width / 2)
	{
		ball.velocity.x = -ball.velocity.x;

		Vec2 rectToBall = position - ball.position;
		rectToBall.normalize();
		ball.velocity.y = impartedYVelocity * rectToBall;
	}
	else
	{
		ball.velocity.y = -ball.velocity.y;
	}
}

void PongRect::update(real dt)
{
	position += velocity * dt;
	rectangle.setPosition(sf::Vector2f(position.x - width / 2, position.y - height / 2));
}

void PongRect::moveUp()
{
	velocity.y = verticalSpeed;
}
void PongRect::moveDown()
{
	velocity.y = -verticalSpeed;
}

void PongRect::noMove()
{
	velocity.y = 0;
}

