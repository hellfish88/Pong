#include "Game.h"
#include <iostream>

namespace Pong {


	Game::Game(int screenWidth, int screenHeight, std::string title) :
		screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

		assert(!IsWindowReady());

		//InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window // Window now created in lobby.cpp

		ball = std::make_shared<Ball>(Circle{  (float)screenWidth / 2, (float)screenHeight / 2, 20 });
		leftPaddle = std::make_shared<Paddle>(10, false);
		rightPaddle = std::make_shared<Paddle>(GetScreenWidth() - 30, true);
		SetTargetFPS(100); // No explaination needed

	}



	void Game::Tick() {

		ClearBackground(backgroundColor);
		BeginDrawing();
		Update();
		Draw(ball.get(), leftPaddle.get(), rightPaddle.get());
		EndDrawing();
		
	}

	void Game::Draw(Ball* ball, Paddle* leftPaddle, Paddle* rightPaddle) {
		DrawCircle(screenWidth / 2, screenHeight / 2, 40, Color{ 160, 32, 240 , 255 });
		DrawLine(screenWidth / 2, 0, screenWidth / 2 + 2, screenHeight, BLACK);
		ball->Draw();
		leftPaddle->Draw();
		rightPaddle->Draw();
		DrawText(TextFormat("%zu", leftPaddle->GetScore()), screenWidth / 4 - 20, 10, 70, WHITE);
		DrawText(TextFormat("%zu", rightPaddle->GetScore()), 3 * screenWidth / 4 - 20, 10, 70, WHITE);

		if (powerup) {
			powerup->Draw();
		}
	}


	void Game::ResetBall() {


		ball->ResetBall();

		rightPaddle->ResetPaddle();
		leftPaddle->ResetPaddle();
		SetBackgroundColor(origBackgroundColor);

		if (powerup)
			powerup = nullptr;
	}

	float Game::GetRandomX() {
		return GetRandomValue((GetScreenWidth() / 4), 3 * (GetScreenWidth() / 4));
	}

	float Game::GetRandomY() {
		return GetRandomValue(20, GetScreenHeight());
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

		if (CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), leftPaddle->GetDimensions())) {
			ball->SetUpdateTime();
			ball->SetNormBool();
			ball->SetNormRatio(leftPaddle->GetNorm(ball->GetPosY()));
			ball->SetSpeedY(-1);
			ball->SetSpeedX(-1);
			if (GetRandomValue(0, 5) == 0) {
				SetBackgroundColor(BLACK);
				ball->DoubleSpeed();

			}
		} else if (CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), rightPaddle->GetDimensions())) {

			ball->SetUpdateTime();
			ball->SetNormBool();
			ball->SetNormRatio(rightPaddle->GetNorm(ball->GetPosY()));
			ball->SetSpeedY(-1);
			ball->SetSpeedX(-1);

			int randomVal = GetRandomValue(0, 5);


			if (randomVal <= 1) {
				if (!powerup) {
					powerup = std::make_shared<DoubleUp>(GetRandomX(), GetRandomY(), ball.get());
				}
			}

			if (randomVal == 0) {
				ball->DoubleSpeed();
				SetBackgroundColor(BLACK);

			}
		}
		if (powerup) {
			if (CheckCollisionCircles(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), Vector2{ powerup->GetX(), powerup->GetY() }, powerup->GetRadius())) {
				powerup->SetDraw(false);
				powerup->Action();
			}
		}



		ball->Update();
		leftPaddle->Update();
		if (rightPaddle->GetCPU()) {

			rightPaddle->UpdateCPU(ball->GetPosY(), ball->GetSpeed());
		}
	}


	Game::~Game() noexcept {
		CloseWindow();

	}
};