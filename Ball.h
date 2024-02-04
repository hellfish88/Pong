#pragma once


#include "raylib.h"
#include "Coords.h"
#include <cmath>

class Ball {

private:
	int speedX;
	int speedY;
	int original_speedX;
	int original_speedY;
	bool has_been_doubled = false;
	Coords coords;
	Vector2 coords2;
	double atan;
public:
	float GetPosX() const;
	float GetPosY() const;
	float GetRadius() const { return coords.radius; }
	double getAtan() { return atan2(coords.y, coords.x); }
	void SetPosX(int, bool reset = false);
	void SetPosY(int, bool reset = false);
	void SetSpeedX(int);
	void SetSpeedY(int);
	void DoubleSpeed();
	void ResetSpeed();
	void SetDoubledBool(bool sant) { has_been_doubled = sant; };
	bool GetDoubleBool() const { return has_been_doubled; };
	int	GetSpeed() const {
		return speedY;
	}
	Ball(Coords);
	void Update();
	void Draw() const;
};