#pragma once


#include "raylib.h"
#include "raymath.h"
#include "Coords.h"
#include <cmath>
#include "Paddel.h"

class Ball {

private:
	int speedX;
	int speedY;
	float speed = 14;
	int original_speedX;
	int original_speedY;
	bool has_been_doubled = false;
	bool customDirection = false;
	Coords coords;
	Vector2 coords2;
	float normRatio;
public:
	float GetPosX() const;
	float GetPosY() const;
	float GetRadius() const { return coords.radius; }
	double getAtan() { return atan2(coords.x,coords.y); }
	void SetPosX(int, bool reset = false);
	void SetPosY(int, bool reset = false);
	void SetSpeedX(int);
	void SetSpeedY(int);
	void DoubleSpeed();
	void ResetSpeed();
	void SetNormRatio(float y) { normRatio = y; }
	void SetNormBool() { customDirection = true; }
	void SetDoubledBool(bool sant) { has_been_doubled = sant; };
	bool GetDoubleBool() const { return has_been_doubled; };
	int	GetSpeed() const {
		return speedY;
	}
	Ball(Coords);
	void Update(Paddle*);
	void Draw() const;
};