#pragma once
#include "Header.h"
#include "PongBall.h"
#include "PongRect.h"
class PongBox {
public:
	PongBox(Vec2 pos, int wid, int hei)
	{
		position = pos;
		width = wid;
		height = hei;
		sf::PrimitiveType l = sf::PrimitiveType::LineStrip;
		box.setPrimitiveType(l);
		box.resize(5);
		box[0].position = sf::Vector2f(pos.x, pos.y);
		box[1].position = sf::Vector2f(pos.x+width, pos.y);
		box[2].position = sf::Vector2f(pos.x+width, pos.y+height);
		box[3].position = sf::Vector2f(pos.x, pos.y+height);
		box[4].position = sf::Vector2f(pos.x, pos.y);

		rectLeft = PongRect(Vec2(position.x + 30, position.y+height/2), 15, 50);
		rectRight = PongRect(Vec2(position.x - 30 + width, position.y + height / 2), 15, 50);
		ball = PongBall(Vec2(position.x + width / 2, position.y + height / 2), 6);
	}

	void collision();

	void yCollision(PongRect& rect);

	void yCollision(PongBall& ball);
	
	bool xCollision(PongBall& ball);

	void rectBallCollision(PongBall& ball, PongRect& rect);

	void draw(sf::RenderWindow& window);

	void reset() {};

	void update(real dt);


public:
	Vec2 position;

	PongBall ball;

	PongRect rectLeft;
	PongRect rectRight;

	sf::VertexArray box;

	int width;
	int height;

};

