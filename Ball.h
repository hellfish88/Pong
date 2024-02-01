#pragma once
#include "raylib.h"
#include "Coords.h"

class Ball {

private:
	int speedX;
	int speedY;
	Coords coords;
	Vector2 coords2;
public:
	float GetPosX() const;
	float GetPosY() const;
	float GetRadius() const { return coords.radius; }
	void SetPosX(int);
	void SetPosY(int);
	void SetSpeedX(int);
	void SetSpeedY(int);
	int GetSpeed() const {
		return speedY;
	}
	Ball(Coords);
	void Update();
	void Draw() const;
};