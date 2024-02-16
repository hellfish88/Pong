#pragma once


#include "raylib.h"
#include "raymath.h"
#include "Circle.h"
#include <cmath>
#include "Paddel.h"
#include "Settings.h"

class Ball {

private:

	float initialSpeed = Settings::Ball::ballSpeed;
	float* speed_multiplier = &Settings::Ball::ballMultiplier;
	float original_speed_multiplier;
	int original_speedX;
	int original_speedY;
	float speedX;
	float speedY;
	bool has_been_doubled = false;
	size_t doubleUpCount = 0;
	bool has_been_doubledByPowerup = false;
	bool customDirection = false;
	Circle coords;
	float normRatio;
	Color color = WHITE;
	// Counter to remove bug where ball gets stuck in paddle
	float timeUpdated;										////
	size_t collisionCount = 0;								////
	//bool beenUpdated = false;								////
	//														////
public:
	float GetPosX() const;
	float GetPosY() const;
	float GetRadius() const { return coords.radius; }
	float GetSpeedMultiplier() { return *speed_multiplier; }
	//double getAtan() { return atan2(coords.x,coords.y); }
	void SetPosX(int, bool reset = false);
	void SetPosY(int, bool reset = false);
	void SetSpeedX(int);
	void SetSpeedY(int);
	void SetSpeedMultiplier(float _multiplier) { *speed_multiplier = _multiplier; }
	void DoubleSpeed();
	void DoubleSpeedFromPowerUp();
	void ResetSpeed();
	void ResetBall();
	void SetNormRatio(float y) { normRatio = y; }
	void SetNormBool() { customDirection = true; }
	void SetDoubledBool(bool sant) { has_been_doubled = sant; };
	void SetDoublePowerUpBool(bool sant) { has_been_doubledByPowerup = sant; };
	void SetOriginalBallMultiplier();
	//void SetCollisionCounter();
	void SetColor(Color colour) { this->color = colour; }
	void SetUpdateTime() {
		timeUpdated = GetTime();
		collisionCount++;
	}
	bool GetDoubleBool() const { return has_been_doubled; };
	int	GetSpeed() const {
		return speedY;
	}
	Ball(Circle);
	void Update();
	void Draw() const;
};