//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_GAME_H
#define SP_Y2S2M2_NEW_GAME_H


#include "player.hpp"
#include <vector>

namespace ariel{}

class Game {
    private:
        Player player1_;
        Player player2_;
        string status_;
        string status_lest_;





    public:
        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
};


#endif //SP_Y2S2M2_NEW_GAME_H
