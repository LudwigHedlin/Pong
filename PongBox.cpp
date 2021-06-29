#include "PongBox.h"

void PongBox::yCollision(PongRect& rect)
{
	if (rect.position.y + rect.height / 2 > position.y + height)
	{
		rect.position.y = -rect.height / 2 + position.y + height;
	}
	else if (rect.position.y - rect.height / 2 < position.y)
	{
		rect.position.y = rect.height / 2 + position.y;
	}
}

void PongBox::yCollision(PongBall& ball)
{
	if (ball.position.y + ball.radius > position.y + height)
	{
		ball.position.y = position.y + height - ball.radius;
		ball.velocity.y = -ball.velocity.y;
	}
	else if (ball.position.y - ball.radius < position.y)
	{
		ball.position.y = position.y + ball.radius;
		ball.velocity.y = -ball.velocity.y;
	}
}

bool PongBox::xCollision(PongBall& ball)
{
	return ball.position.x + ball.radius > position.x + width || ball.position.x - ball.radius < position.x;
}

void PongBox::collision()
{
	yCollision(ball);
	yCollision(rectLeft);
	yCollision(rectRight);
	if (rectLeft.isCollision(ball))
	{
		rectLeft.collision(ball);
	}
	else if (rectRight.isCollision(ball))
	{
		rectRight.collision(ball);
	}
}

void PongBox::update(real dt)
{
	ball.update(dt);
	rectLeft.update(dt);
	rectRight.update(dt);
}

void PongBox::draw(sf::RenderWindow& window)
{
	window.draw(box);
	ball.draw(window);
	window.draw(rectLeft.rectangle);
	window.draw(rectRight.rectangle);

}