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
	size_t score = 0;
public:
	//int GetX();
	float GetY() const{ return posy; }
	float GetX() const { return posx; }
	float GetHeight() const { return height; }
	Paddle(int posx) :
		posx(posx), posy((GetScreenHeight() /2)), thicc(20), height(GetScreenHeight() / 6) {
		coordinates.x = posx;
		coordinates.y = posy;
	};
	void Draw()  {
		//DrawRectangle(posx, posy, 20, height, WHITE);
		DrawRectangleRounded(GetDimensions(), 10, 10, WHITE); // Color ruby red
	};
	void SetY(int);
	void Update(int speed);
	void SetScore() { score++; }
	size_t GetScore() { return score; }
	Rectangle GetDimensions() const;


};