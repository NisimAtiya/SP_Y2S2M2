//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_PLAYER_H
#define SP_Y2S2M2_NEW_PLAYER_H
#include <string>

using namespace std;
namespace ariel{}

class Player {
    private:
    string name;

    public:
        int stacksize();
        int cardesTaken();

        Player(string);
};




#endif //SP_Y2S2M2_NEW_PLAYER_H
