#pragma once
#include "raylib.h"
#include "Coords.h"

class Ball {

private:
	float posX, posY;
	int speedX;
	int speedY;
	int radius;
	Coords coords;
public:
	int GetPosX() const;
	int GetPosY() const;
	int GetRadius() const { return coords.radius; }
	void SetPosX(int);
	void SetPosY(int);
	void SetSpeedX(int);
	void SetSpeedY(int);
	Ball(Coords);
	void Update();
	void Draw() const;
};