#pragma once
#include "raylib.h"
#include "Coords.h"

class Paddle {
private:
	float posy;
	float posx;
	const float thicc;
	const float height;
	Vector2 coordinates;
public:
	//int GetX();
	float GetY() const{ return posy; }
	float GetX() const { return posx; }
	float GetHeight() const { return height; }
	Paddle(int posx) :
		posx(posx), posy((GetScreenHeight() /2)), thicc(20), height(GetScreenHeight() / 6) {
	};
	void Draw()  {
		DrawRectangle(posx, posy, 20, height, WHITE);
	};
	void SetY(int);
	void Update(int speed);
	Rectangle GetDimensions() const;


};