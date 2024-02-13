#include "Lobby.h"


int main(void) {

    const int screenWidth = 1280;
    const int screenHeight = 800;


    //Pong::Game game(screenWidth, screenHeight, "Spel");

    std::shared_ptr<Lobby> game = std::make_shared<Lobby>(screenWidth, screenHeight, "Spel");
    //std::shared_ptr<Pong::Game> game = std::make_shared<Pong::Game>(screenWidth, screenHeight, "Spel");


    while (!game->GameShouldClose()) {
        game->Make();
    }



    return 0;
}