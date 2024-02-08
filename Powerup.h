#pragma once
#include "raylib.h"
#include "Ball.h"



class Powerup {
protected:
	Vector2 position;
	float radius = 30;
	Color color;
	Ball* ball;
	Paddle* paddle;
public:
	Powerup(float _x, float _y) :
		position{ .x = _x, .y = _y }, color(WHITE), ball(nullptr), paddle(nullptr) {
	}
	float GetY() { return position.y; }
	float GetX() { return position.x; }
	float GetRadius() { return radius; }
	void SetY(float);
	void SetX(float);
	void SetColor(Color _color) { color = _color; }
	//void Delete() { delete this; }
	virtual void Draw() = 0;
	virtual void Action() = 0;
	virtual void SetDraw(bool) = 0;
};

class DoubleUp : public Powerup {
private:
	bool shouldDraw = true;
public:
	DoubleUp(float _x, float _y, Ball* _ball) :
		Powerup(_x, _y){
		ball = _ball;
	}
	void Draw() override;
	void Action() override;
	void SetDraw(bool _bool) override { shouldDraw = _bool; }

};