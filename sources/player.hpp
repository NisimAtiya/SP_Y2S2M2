//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_PLAYER_H
#define SP_Y2S2M2_NEW_PLAYER_H
#include <string>
#include "card.hpp"
#include <vector>

using namespace std;
namespace ariel{}

class Player {
private:
    string name_;
    bool is_playing_now_;
    int cardes_Taken_;
    vector<Card> packet;


public:
    int stacksize();
    int cardesTaken();
    Player(string);
    Player();
    void set_cardesTaken(int);
    string getname();
    void set_name(string);
    bool is_playing_now();
    void set_is_playing_now(bool);
    void take_card(Card);

};




#endif //SP_Y2S2M2_NEW_PLAYER_H