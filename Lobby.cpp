#include "Lobby.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Lobby::Lobby(int _screenWidht, int _screenHeight, std::string _title)
	: screenHeight(_screenHeight), screenWidth(_screenWidht), title(_title){

	assert(!IsWindowReady());

	InitWindow(screenWidth, screenHeight, title.c_str());
	SetTargetFPS(100); // No explaination needed
}

Lobby::~Lobby() noexcept {
	CloseWindow();
}

void Lobby::Make() {
	ClearBackground(backgroundColor);
	BeginDrawing();

	if (GuiButton(Rectangle{buttonX, buttonY, buttonWidth, buttonHeight}, "Start Game!")) {
		std::shared_ptr<Pong::Game> game = std::make_shared<Pong::Game>(screenWidth, screenHeight, "Pong");
		

		while (!game->GameShouldClose()) {
			game->Tick();
			//CloseWindow();

		}
	}
	EndDrawing();
}
