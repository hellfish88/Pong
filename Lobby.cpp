#include "Lobby.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Lobby::Lobby(int _screenWidht, int _screenHeight, std::string _title)
	: screenHeight(_screenHeight), screenWidth(_screenWidht), title(_title){

	assert(!IsWindowReady());

	//InitWindow(screenWidth, screenHeight, title.c_str());
	//SetTargetFPS(100); // No explaination needed
}

Lobby::~Lobby() noexcept {
	CloseWindow();
}

SettingsMenu::~SettingsMenu() noexcept {
	CloseWindow();
}

void SettingsMenu::draw() {
	float _buttonY = buttonY;
	BeginDrawing();
	ClearBackground(RED);

	for (std::string setting : SettingsMenu::settings) {
		DrawText(setting.c_str(), buttonX, _buttonY, 20, GREEN);
		_buttonY += buttonSpacing;
		if (GuiButton(Rectangle{ screenWidth - (buttonWidth * 2), 0, buttonWidth, buttonHeight }, "Back")) {
			this->Make();
			
		}

	}
	EndDrawing();
}


void Lobby::Make() {

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(backgroundColor);
		

		if (GuiButton(Rectangle{ buttonX, buttonY, buttonWidth, buttonHeight }, "Start Game!")) {
			std::shared_ptr<Pong::Game> game = std::make_shared<Pong::Game>(screenWidth, screenHeight, "Pong");


			while (!game->GameShouldClose()) {
				game->Tick();
				
			}
			game.reset();
		}
		if (GuiButton(Rectangle{ buttonX, buttonY + buttonHeight + 20, buttonWidth, buttonHeight }, "Settings")) {

			std::shared_ptr<SettingsMenu> settingsmenu = std::make_shared<SettingsMenu>(screenWidth, screenHeight, "Settings");
			while (!settingsmenu->GameShouldClose()) {
				settingsmenu->draw();
			}
			settingsmenu.reset();
		}
		EndDrawing();
	}
}

