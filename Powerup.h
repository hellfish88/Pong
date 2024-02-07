#pragma once
#include "raylib.h"

class Powerup {
protected:
	Vector2 position;
	float radius = 30;
	Color color;
public:
	Powerup(float _x, float _y) :
		position{ .x = _x, .y = _y }, color(WHITE) {
	}
	float GetY() { return position.y; }
	float GetX() { return position.x; }
	void SetY(float);
	void SetX(float);
	void SetColor(Color _color) { color = _color; }
	void Delete() { delete this; }
	virtual void Draw() = 0;
};

class DoubleUp : public Powerup {
public:
	DoubleUp(float _x, float _y) :
		Powerup(_x, _y) { }
	void Draw();


};