#include "Game.h"


Game::Game(int screenWidth, int screenHeight, std::string title) :
	screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

	assert(!IsWindowReady());

	InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window

	ball = std::make_shared<Ball>(Coords{.x = (float)screenWidth / 2, .y = (float)screenHeight / 2, .radius = 20 });
	leftPaddle = std::make_shared<Paddle>(10);
	rightPaddle = std::make_shared<Paddle>(GetScreenWidth() - 30);


	SetTargetFPS(60); // No explaination needed

}

void Game::Tick() {

	ClearBackground(BLACK);
	BeginDrawing();
	Update();
	Draw(ball.get(), leftPaddle.get(), rightPaddle.get());
	EndDrawing();
}



void Game::Draw(Ball* ball, Paddle* leftPaddle, Paddle* rightPaddle) {
	ball->Draw();
	leftPaddle->Draw();
	rightPaddle->Draw();
	DrawText(hejsan.c_str(), ((screenWidth / 2) - hejsan.size() * 2), screenHeight / 2, 40, RED);
	DrawText(TextFormat("%zu", leftPaddle->GetScore()), screenWidth / 4 - 20, 10, 70, RED);
	DrawText(TextFormat("%zu", rightPaddle->GetScore()), 3 * screenWidth / 4 - 20, 10, 70, RED);
}

void Game::UpdateCPU(Paddle *cpu, const Ball* ball) {
	if (ball->GetPosY() >= cpu->GetY()) {
		cpu->SetY(ball->GetSpeed() - 4);
	} else {
		cpu->SetY((ball->GetSpeed() -1 ) - 2);
	}
}

void Game::ResetBall() {
	if (GetRandomValue(1, 2) == 1) {
		ball->SetSpeedX(-1);
		ball->SetSpeedY(-1);
	} else {
		ball->SetSpeedX(1);
		ball->SetSpeedY(1);
	}
	ball->SetPosX(screenWidth / 2, true);
	ball->SetPosY(screenHeight / 2, true);
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

	if ((CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(),leftPaddle->GetDimensions())) ||
		(CheckCollisionCircleRec(Vector2{ ball->GetPosX(), ball->GetPosY() }, ball->GetRadius(), rightPaddle->GetDimensions()))
		) {
		ball->SetSpeedY(-1);
		ball->SetSpeedX(-1);
	}


	ball->Update();
	leftPaddle->Update(7*2);
}
