#pragma once
#include "raylib.h"

class Paddle {
private:
	int posy;
	int posx;
	const int thicc;
	const int height;
public:
	//int GetX();
	int GetY() const{ return posy; }
	int GetX() const { return posx; }
	int GetHeight() const { return height; }
	Paddle(int posx) :
		posx(posx), posy((GetScreenHeight() /2)), thicc(20), height(GetScreenHeight() / 6) {
	};
	void Draw()  {
		DrawRectangle(posx, posy, 20, height, WHITE);
	};
	void SetY(int);
	void Update(int speed);


};