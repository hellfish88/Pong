#include "Game.h"


Game::Game(int screenWidth, int screenHeight, std::string title) :
	screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

	assert(!IsWindowReady());

	InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window

	ball = std::make_shared<Ball>(Coords{.x = (float)screenWidth / 2, .y = (float)screenHeight / 2, .radius = 20 });
	leftPaddle = std::make_shared<Paddle>(10);
	rightPaddle = std::make_shared<Paddle>(GetScreenWidth() - 30);
	//Image temple = LoadImage(".\temple.png");
	//Texture2D texture = LoadTextureFromImage(temple);
	//UnloadImage(temple);
	//temple = LoadImageFromTexture(texture);
	//UnloadTexture(texture);
	//texture = LoadTextureFromImage(temple);
	//UnloadImage(temple);


	SetTargetFPS(60); // No explaination needed

}

Game::~Game() noexcept {
	CloseWindow();
	//UnloadTexture(texture);
	//UnloadImage(temple);
}

void Game::Tick() {

	ClearBackground(Color{ 225, 87, 51, 255 });
	BeginDrawing();
	Update();
	Draw(ball.get(), leftPaddle.get(), rightPaddle.get());
	EndDrawing();
}



void Game::Draw(Ball* ball, Paddle* leftPaddle, Paddle* rightPaddle) {
	ball->Draw();
	leftPaddle->Draw();
	rightPaddle->Draw();
	DrawCircle(screenWidth / 2, screenHeight / 2, 40, Color{ 160, 32, 240 , 200 });
	DrawText(TextFormat("%zu", leftPaddle->GetScore()), screenWidth / 4 - 20, 10, 70, WHITE);
	DrawText(TextFormat("%zu", rightPaddle->GetScore()), 3 * screenWidth / 4 - 20, 10, 70, WHITE);
	DrawLine(screenWidth / 2, 0, screenWidth / 2 + 2, screenHeight, BLACK);
	
	
}

void Game::UpdateCPU(Paddle *cpu, const Ball* ball) { // move CPU paddle

	int speed = ball->GetSpeed();
	size_t limitation = 0;
	cpu->SetY((speed <= 0) ? speed - limitation : speed + limitation);

}

void Game::ResetBall() {

	int direction_choices[2] = { -1, 1 };

	ball->SetSpeedX(direction_choices[GetRandomValue(0, 1)]);
	ball->SetSpeedY(direction_choices[GetRandomValue(0, 1)]);

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
