#pragma once
#include "raylib.h"
#include "Coords.h"

class Paddle {
private:
	Rectangle stats;
	size_t score = 0;
public:
	//int GetX();
	float GetY() const{ return stats.y; }
	float GetX() const { return stats.x; }
	float GetHeight() const { return stats.height; }
	Paddle(float posx) :
		stats{.x = posx, .y = (float)GetScreenHeight() / 2, .width = 20, .height = (float)GetScreenHeight() / 6 } {
	};
	void Draw()  {
		//DrawRectangle(posx, posy, 20, height, WHITE);
		DrawRectangleRounded(GetDimensions(), 10, 10, WHITE); // Color ruby red
	};
	void SetY(int);
	void Update(float speed);
	void SetScore() { score++; }
	size_t GetScore() { return score; }
	Rectangle GetDimensions() const;
	

};