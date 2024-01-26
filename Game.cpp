#include "Game.h"

Game::Game(int screenWidth, int screenHeight, std::string title) :
	screenWidth(screenWidth), screenHeight(screenHeight), title(title) {

	InitWindow(screenWidth, screenHeight, title.c_str()); // Create main window


	SetTargetFPS(60); // No explaination needed

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(WHITE);

		DrawText("woho!", 400, 200, 30, BLACK); // What to draw. shapes? 

		EndDrawing();

	}
	CloseWindow();
}
