#pragma once
#define _USE_MATH_DEFINES

#include <string>
#include <raylib.h>
#include <assert.h>
#include "Ball.h"
#include <memory>
#include "Paddel.h"
#include "Powerup.h"
#include <vector>
#include <typeinfo>


namespace Pong {

	class Game {
		//friend class Ball;
	public:
		Game() = default;
		Game(int screenWidth, int screenHeight, std::string title);
		~Game() noexcept;
		/// 

		void Tick();

		bool GameShouldClose() const { return WindowShouldClose(); }
	private:

		void Update();
		void Draw(Ball* ball, Paddle* leftPaddle, Paddle* RightPaddle);
		//void UpdateCPU(Paddle*, const Ball*);
		void ResetBall();
		void SetBackgroundColor(Color colour) { this->backgroundColor = colour; }
		float GetRandomX(); // for the powerup classes to spawn 
		float GetRandomY();
		Color backgroundColor = Color{ 225, 87, 51, 255 };
		const Color origBackgroundColor = Color{ 225, 87, 51, 255 };
		int screenWidth;
		int screenHeight;
		std::string hejsan = "";
		std::string title;
		std::shared_ptr<Ball> ball;
		std::shared_ptr<Paddle> leftPaddle;
		std::shared_ptr<Paddle> rightPaddle;
		std::shared_ptr<Powerup> powerup;
		
	};


}