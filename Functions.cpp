#include "Functions.h"

namespace Pong {

	void Game::ResetBall(Ball *ball) {

		int direction_choices[2] = { -1, 1 };

		ball->SetSpeedX(direction_choices[GetRandomValue(0, 1)]);
		ball->SetSpeedY(direction_choices[GetRandomValue(0, 1)]);

		ball->SetPosX(screenWidth / 2, true);
		ball->SetPosY(screenHeight / 2, true);
		ball->SetDoubledBool(false);
		ball->ResetSpeed();
		if (GetRandomValue(0, 100) % 33 == 0) {
			ball->DoubleSpeed();
		}
	}

	void Game::UpdateCPU(Paddle* cpu, const Ball* ball) { // move CPU paddle

		int speed = (ball->GetDoubleBool()) ? (ball->GetSpeed() / 2) : ball->GetSpeed();
		size_t limitation = 0;
		if (GetRandomValue(0, 100) % 10 == 0) {
			limitation = 4;
		} else if (GetRandomValue(0, 100) % 5 == 0) {
			limitation = -2;
		}
		cpu->SetY((speed <= 0) ? speed - limitation : speed + limitation);

	}


}