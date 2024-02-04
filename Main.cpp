#include "Game.h"


int main(void) {

    const int screenWidth = 1280;
    const int screenHeight = 800;


    Pong::Game game(screenWidth, screenHeight, "Spel");

    while (!game.GameShouldClose()) {
        game.Tick();
    }



    return 0;
}