#include "Paddel.h"

float Paddle::GetNorm(float impactY) const {
	float neutral = GetMidY();
	float max = neutral + (stats.height / 2);

	float distanceFromCenter = impactY - neutral;
	float norm = distanceFromCenter / (stats.height / 2);
	return std::clamp(norm, -1.0f, 1.0f);

}

void Paddle::SetY(float y) {

	if (!((stats.y + y) >= GetScreenHeight() - (stats.height) || (stats.y + y) <= 0)) {
		stats.y += y * GetFrameTime() * 60;
	}
}

void Paddle::Update() {

	if (IsKeyDown(KEY_DOWN)) {
		SetY(paddleSpeed);
	} else if (IsKeyDown(KEY_UP)) {
		SetY(paddleSpeed * -1);
	}

	if (this->GetY() + this->GetHeight() > GetScreenHeight()) {
		this->ResetPaddle();
	}

	if (this->GetY() < 0) {
		this->ResetPaddle();
	}

}

void Paddle::ResetPaddle() {
	stats.y = (float)GetScreenHeight() / 2;
}

Rectangle Paddle::GetDimensions() const {
	return stats;
}

void Paddle::UpdateCPU(float ballPos, float ballspeed) { // move CPU paddle


	size_t limitation{ 0 };

	//if (GetRandomValue(0, 100) % 10 == 0) {
	//	limitation = 4;
	//} else if (GetRandomValue(0, 100) % 5 == 0) {
	//	limitation = -2;
	//}


	float paddieDirectionSpeed = (ballspeed <= 0) ? -1 : 1;
	//speed *= paddieDirectionSpeed;
	float speed{ 0 };
	
	//float ballPos = ball->GetPosY();
	float paddlePos = this->GetMidY();
	float diff = std::abs(ballPos - paddlePos);
	if (ballPos < paddlePos) {
		speed = -7;
	} else {
		speed = 7;
	}
	// Try to remove tremble of paddle
	if (diff < 20)
		speed = 1;

	this->SetY((speed <= 0) ? speed - limitation : speed + limitation);
	//cpu->SetY(speed);

}