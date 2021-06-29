#pragma once
#include "Vec2.h"
#include <SFML/Graphics.hpp>
#include "Header.h"
#include "PongBall.h"
class PongRect {
public:
	PongRect() {};

	PongRect(Vec2 pos, real widthx, real heighty)
	{
		position = pos;
		width = widthx;
		height = heighty;
		rectangle.setSize(sf::Vector2f(width,height));
		rectangle.setPosition(sf::Vector2f(pos.x - width/2, pos.y - height/2));
	}


	void collision(PongBall& ball);
	
	bool isCollision(PongBall& ball);

	bool isInside(Vec2& pos);

	void draw(sf::RenderWindow& window);

	void moveDown();

	void moveUp();

	void noMove();

	void update(real dt);

public:
	Vec2 position;
	Vec2 velocity;
	real width;
	real height;
	real verticalSpeed = 200;

	sf::RectangleShape rectangle;

private:
	Vec2 impartedYVelocity=Vec2(0,200);
};

