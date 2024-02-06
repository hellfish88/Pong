#include "Game.h"
#include <iostream>

namespace Pong {


	Game::Game(int screenWidth, int screenHeight, std::string title) :
		screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

		assert(!IsWindowReady());

		InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window

		ball = std::make_shared<Ball>(Coords{ .x = (float)screenWidth / 2, .y = (float)screenHeight / 2, .radius = 20 });
		leftPaddle = std::make_shared<Paddle>(10);
		rightPaddle = std::make_shared<Paddle>(GetScreenWidth() - 30);

		SetTargetFPS(60); // No explaination needed

	}



	void Game::Tick() {

		ClearBackground(Color{ 225, 87, 51, 255 });
		BeginDrawing();
		Update();
		Draw(ball.get(), leftPaddle.get(), rightPaddle.get());
		EndDrawing();
		double degree = ball->getAtan();
		//float degrees = std::fmod(((float)degree * 180.0f / M_PI) + 360.0f, 360.0f);
		//double degrees = degree + 360 % 360;

		//std::cout << "Ball angle: " << degree  << std::endl;
	}

	void Game::Draw(Ball* ball, Paddle* leftPaddle, Paddle* rightPaddle) {
		DrawCircle(screenWidth / 2, screenHeight / 2, 40, Color{ 160, 32, 240 , 255 });
		DrawLine(screenWidth / 2, 0, screenWidth / 2 + 2, screenHeight, BLACK);
		ball->Draw();
		leftPaddle->Draw();
		rightPaddle->Draw();
		DrawText(TextFormat("%zu", leftPaddle->GetScore()), screenWidth / 4 - 20, 10, 70, WHITE);
		DrawText(TextFormat("%zu", rightPaddle->GetScore()), 3 * screenWidth / 4 - 20, 10, 70, WHITE);

		/// debug
		//if (ball->GetDoubleBool()) {
		//	DrawText("its doubled now", screenWidth / 2, screenHeight / 4 * 2, 40, BLACK);
		//	DrawText(TextFormat("%i", ball->GetSpeed()), screenWidth / 2, screenHeight / 4 * 3, 40, BLACK);
		//}


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

	void Game::ResetBall() {

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


	void Game::Update() {
		if (ball->GetPosX() + ball->GetRadius() >= screenWidth) {
			leftPaddle->SetScore();
			ResetBall();

		}
		if (ball->GetPosX() - ball->GetRadius() <= 0) {
			rightPaddle->SetScore();
			ResetBall();
		}

		if (ball->GetPosY() + ball->GetRadius() >= GetScreenHeight() || ball->GetPosY() - ball->GetRadius() <= 0) {
			ball->SetSpeedY(-1);
		}



		UpdateCPU(rightPaddle.get(), ball.get());
		//UpdateCPU(leftPaddle.get(), ball.get());

		if (CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), leftPaddle->GetDimensions())) {
			std::cout << "Norm: " << leftPaddle->GetNorm(ball->GetPosY()) << std::endl;
			ball->SetSpeedY(-1);
			ball->SetSpeedX(-1);
			if (GetRandomValue(0, 5) == 0) {
				ball->DoubleSpeed();
			}
		} else if (CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), rightPaddle->GetDimensions())) {
			std::cout << "Norm: " << rightPaddle->GetNorm(ball->GetPosY()) << std::endl;
			ball->SetSpeedY(-1);
			ball->SetSpeedX(-1);
			if (GetRandomValue(0, 5) == 0) {
				ball->DoubleSpeed();
			}
		}


		ball->Update(rightPaddle.get());
		leftPaddle->Update(7);
	}


	Game::~Game() noexcept {
		CloseWindow();

	}
};