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
    int played;
    int win;
    int loss;
    int draw;



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
    Card get_card();
    void pull_card();
    void increase_cardes_Taken_(int);
    void increase_played();
    void increase_win();
    void increase_loss();
    void increase_draw();
    void printStats_();

};




#endif //SP_Y2S2M2_NEW_PLAYER_H