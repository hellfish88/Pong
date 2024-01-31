#include "Game.h"


Game::Game(int screenWidth, int screenHeight, std::string title) :
	screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

	assert(!IsWindowReady());

	InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window

	ball = std::make_shared<Ball>(Coords{.x = screenWidth / 2, .y = screenHeight / 2, .radius = 20 });
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

bool Game::CollisionDetection(Coords& ball, Coords& paddle) {
	return false;
}


void Game::Draw(Ball* ball, Paddle* leftPaddle, Paddle* rightPaddle) {
	ball->Draw();
	leftPaddle->Draw();
	rightPaddle->Draw();
	DrawText(hejsan.c_str(), ((screenWidth / 2) - hejsan.size() * 2), screenHeight / 2, 40, RED);
}


void Game::Update() {
	if (ball->GetPosX() + ball->GetRadius() >= GetScreenWidth() || ball->GetPosX() - ball->GetRadius() <= 0) {
		ball->SetSpeedX(-1);
	}
	if (ball->GetPosY() + ball->GetRadius() >= GetScreenHeight() || ball->GetPosY() - ball->GetRadius() <= 0) {
		ball->SetSpeedY(-1);
	}

	if ((ball->GetPosX() - ball->GetRadius() <= leftPaddle->GetX() + 20 && (ball->GetPosY() <= leftPaddle->GetY() || ball->GetPosY() >= leftPaddle->GetY() + leftPaddle->GetHeight()))) {
		ball->SetSpeedY(-1);
		ball->SetSpeedX(-1);
	}

	ball->Update();
	leftPaddle->Update(7*2);
}
