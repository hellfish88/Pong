#pragma once
#include <string>
#include <raylib.h>

class Game {
public:
	Game() = default;
	Game(int screenWidth, int screenHeight, std::string title);
private:
	int screenWidth;
	int screenHeight;
	std::string title;
};