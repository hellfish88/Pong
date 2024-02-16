#pragma once
//#include "Ball.h"
#include "raylib.h"
//#include "Coords.h"
#include <algorithm>
#include "Settings.h"


class Paddle {
private:
	float paddleSpeed = Settings::Paddle::paddleSpeed;
	float CPUpaddleSpeed = Settings::Paddle::cpuPaddleSpeed;
	Rectangle stats;
	size_t score = 0;
	bool singlePlayer = Settings::General::singlePlayer;
	bool isCPU = false;
public:
	//int GetX();
	void UpdateCPU(float ballPos, float ballspeed);
	float GetY() const{ return stats.y; }
	float GetX() const { return stats.x; }
	float GetHeight() const { return stats.height; }
	float GetMidY() const { return stats.y + stats.height / 2; }
	float GetNorm(float impactY) const;
	bool GetCPU() const { return isCPU; }
	Paddle(float posx, bool cpu) :
		stats{stats.x = posx, stats.y = (float)GetScreenHeight() / 2, stats.width = 20, stats.height = (float)GetScreenHeight() / 6 }, isCPU(cpu) {
	};
	void Draw() const {
		//DrawRectangle(posx, posy, 20, height, WHITE);
		DrawRectangleRounded(GetDimensions(), 10, 10, WHITE); // Color ruby red
	};
	void SetY(float);
	void Update();
	void SetScore() { score++; }
	
	void ResetPaddle();
	size_t GetScore() const { return score; }
	Rectangle GetDimensions() const;
	

};