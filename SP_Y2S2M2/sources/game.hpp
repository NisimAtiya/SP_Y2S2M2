//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_GAME_H
#define SP_Y2S2M2_NEW_GAME_H


#include "player.hpp"
namespace ariel{}

class Game {

public:
    Game(Player, Player);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();
};


#endif //SP_Y2S2M2_NEW_GAME_H
