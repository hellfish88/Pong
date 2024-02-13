#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <assert.h>
#include "Game.h"
//#define RAYGUI_IMPLEMENTATION




class Lobby {
private:
	int screenHeight;
	int screenWidth;
	std::string title;
	const float buttonWidth = 150;
	const float buttonHeight = 40;
	const float buttonSpacing = 20;
	const float fontSize = 15;
	const Color backgroundColor = GRAY;
	const Color buttonTextColor = RED;
	float buttonX = (screenWidth - buttonWidth) / 2;
	float buttonY = (screenHeight - buttonHeight * 2 + buttonSpacing) / 2;

public:
	Lobby(int _screenHeight, int _screenWidht, std::string _title);
	~Lobby() noexcept;
	// // // 
	bool GameShouldClose() const { return WindowShouldClose(); }
	void Make();
};