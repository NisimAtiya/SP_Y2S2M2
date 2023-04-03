//
// Created by Nisim Atiya on 22/03/2023.
//

#include "game.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(Player &player1, Player &player2) {
    //צריך לבדוק אם שני השחקנים זה אותו שחקן
    if (player2.is_playing_now() || player1.is_playing_now()) {
        throw std::invalid_argument("One of the players is already playing");
    }
    //Enter the players
    this->player1_ = player1;
    this->player2_ = player2;
    //Create a package
    int index = 0;
    Card cards[52];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if (i == 1) {
                cards[index] = Card(j, "CLUB");
            } else if (i == 2) {
                cards[index] = Card(j, "DIAMOND");
            } else if (i == 3) {
                cards[index] = Card(j, "HEART");
            } else {
                cards[index] = Card(j, "SPADE");
            }
            index++;
        }
    }
    //Shuffle the cards and put them in the pack and dealing the cards among the players
    int cnt = 0;
    while (cnt != 52) {
        srand(time(NULL)); // seed the random number generator with the current time
        int i = rand() % 52; // generate a random number between 0 and 51
        while(cards[i].get_value()==0){
            srand(time(NULL)); // seed the random number generator with the current time
            i = rand() % 52;
        }
        if (cnt%2==0){
            this->player1_.take_card(cards[i]);
        } else{
            this->player2_.take_card(cards[i]);
        }
        cnt++;
        cards[i].set_value(0);
    }
    this->status_lest_="";
    this->status_="";
}

void Game::playTurn() {
    Card card_p1 = this->player1_.get_card();
    Card card_p2 = this->player2_.get_card();
    int val_p1 = card_p1.get_value();
    int val_p2 = card_p2.get_value();
    string temp_status="";
    int cnt_draw=0;

    //A case of a draw
    while (val_p1 == val_p2) {
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                " played " + card_p2.toString() + " - draw.\n";

        this->player1_.pull_card();
        this->player2_.pull_card();
        this->player1_.pull_card();
        this->player2_.pull_card();
        card_p1 = this->player1_.get_card();
        card_p2 = this->player2_.get_card();
        val_p1 = card_p1.get_value();
        val_p2 = card_p2.get_value();
        cnt_draw++;
    }
    //A case where one of the players got 1
    if(val_p1==1){
        if (val_p2==2){
                temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                               " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
            if (cnt_draw!=0){
                this->player2_.increase_cardes_Taken_(cnt_draw*6);
            }
            else{
                this->player2_.increase_cardes_Taken_(2);
            }
        } else{
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
            if (cnt_draw!=0){
                this->player1_.increase_cardes_Taken_(cnt_draw*6);
            }
            else{
                this->player1_.increase_cardes_Taken_(2);
            }
        }

    }
    if(val_p2==1){
        if (val_p1==2){
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
            if (cnt_draw!=0){
                this->player1_.increase_cardes_Taken_(cnt_draw*6);
            }
            else{
                this->player1_.increase_cardes_Taken_(2);
            }
        } else{
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
            if (cnt_draw!=0){
                this->player2_.increase_cardes_Taken_(cnt_draw*6);
            }
            else{
                this->player2_.increase_cardes_Taken_(2);
            }
        }

    }
    if(val_p2<val_p1){
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                       " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
        if (cnt_draw!=0){
            this->player1_.increase_cardes_Taken_(cnt_draw*6);
        }
        else{
            this->player1_.increase_cardes_Taken_(2);
        }
    }
    if(val_p2>val_p1){
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                       " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
        if (cnt_draw!=0){
            this->player2_.increase_cardes_Taken_(cnt_draw*6);
        }
        else{
            this->player2_.increase_cardes_Taken_(2);
        }
    }
    this->player1_.pull_card();
    this->player2_.pull_card();
    this->status_lest_=temp_status;
    this->status_+=status_lest_;

}



void Game::printLastTurn() {
    cout << "printLastTurn" << endl;
}

void Game::playAll() {
    cout << "playAll" << endl;
}

void Game::printWiner() {
    cout << "printWiner" << endl;
}

void Game::printLog() {
    cout << "printLog" << endl;
}

void Game::printStats() {
    cout << "printStats" << endl;
}
