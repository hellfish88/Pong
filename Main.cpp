#include "Lobby.h"


int main(void) {

    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 800;


    InitWindow(screenWidth, screenHeight, "Pong");
    //SetTargetFPS(100); // No explaination needed

    std::shared_ptr<Lobby> game = std::make_shared<Lobby>(screenWidth, screenHeight, "Spel");



    while (!game->GameShouldClose()) {
        game->Make();
    }



    return 0;
}