#include "Lobby.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>

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

	GuiToggle(Rectangle{ 50, 50, buttonWidth , buttonHeight }, "Multiplayer", &Settings::General::singlePlayer);


	for (auto setting : SettingsMenu::settings) {
		//DrawText(setting.c_str(), buttonX, _buttonY, 20, GREEN);
		GuiSlider(Rectangle{ buttonX, _buttonY, buttonWidth, buttonHeight }, setting.name.c_str(), "Max", setting.setting, setting.min, setting.max);
		DrawText(TextFormat("%d", (int)*(setting.setting)), buttonX - 20, _buttonY, 20, BLACK);
		//GuiValueBox(Rectangle{ buttonX, _buttonY + buttonSpacing, buttonWidth + 50, buttonHeight }, setting.first.c_str(), (int*)setting.second, 0, 100, true);
		_buttonY += buttonSpacing;
		//std::cout << Settings::Paddle::cpuPaddleSpeed << std::endl; // debug
	}
	

	if (GuiButton(Rectangle{ screenWidth - (buttonWidth * 2), 0, buttonWidth, buttonHeight }, "Back")) {
		this->Make();
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

