#pragma once
#include <string>
#include <raylib.h>
#include <assert.h>
#include "Ball.h"
#include <memory>
#include "Paddel.h"
#include "Coords.h"

class Game {
	//friend class Ball;
public:
	Game() = default;
	Game(int screenWidth, int screenHeight, std::string title);
	~Game() noexcept { CloseWindow(); }
	/// 

	void Tick();
	bool CollisionDetection(Coords&, Coords&);

	bool GameShouldClose() const { return WindowShouldClose(); }
private:
	
	void Update();
	void Draw(Ball* ball, Paddle* leftPaddle, Paddle* RightPaddle);
	int screenWidth;
	int screenHeight;
	std::string hejsan = "Fisk";
	std::string title;
	std::shared_ptr<Ball> ball;
	std::shared_ptr<Paddle> leftPaddle;
	std::shared_ptr<Paddle> rightPaddle;
};


