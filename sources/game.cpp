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

Game::Game(Player &player1, Player &player2):
        player1_(player1),player2_(player2)
{

    // Checking that a player is not already in the middle of a game
    if (player2.is_playing_now() || player1.is_playing_now()) {
        throw std::invalid_argument("One of the players is already playing");
    }
    this->cnt_Update_statistics=0;
    this->player1_.increase_played();
    this->player2_.increase_played();

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
    //Shuffle the cards and put them in the pack
    srand(time(NULL)); // seed the random number generator with the current tim
    for (int i = 0; i < 1000; ++i) {
        int index = i % 51;
        int rnd = rand() % 52; // generate a random number between 0 and 51
        Card t =cards[rnd];
        cards[rnd]=cards[index];
        cards[index]=t;
    }
    // dealing the cards among the players
    for (int i = 0; i < 52; ++i) {
        if (i%2==0){
            this->player1_.take_card(cards[i]);
        } else{
            this->player2_.take_card(cards[i]);
        }
    }
    this->status_lest_="";
    this->status_="";
    this->player1_.set_is_playing_now(true);
    this->player2_.set_is_playing_now(true);

}

void Game::playTurn() {
    // Checking that a player is not playing against himself
    if(&this->player1_ == &this->player2_){
        throw std::invalid_argument("A player cannot play against himself");
    }
    //If There are no cards in the packan error is thrown
    if(this->player1_.stacksize()==0){
        throw invalid_argument("There are no cards in the pack");
    }

    Card card_p1 = this->player1_.get_card();
    Card card_p2 = this->player2_.get_card();
    int val_p1 = card_p1.get_value();
    int val_p2 = card_p2.get_value();
    string temp_status="";
    int card_on=2;


    //A case of a draw
    while (val_p1 == val_p2) {
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                       " played " + card_p2.toString() + " - draw.\n";

        this->player1_.pull_card();
        this->player2_.pull_card();
        // Checks if there are more cards to draw
        if(this->player1_.stacksize()==0){
            this->player2_.increase_cardes_Taken_(card_on/2);
            this->player2_.increase_cardes_Taken_(card_on/2);
            this->player1_.set_is_playing_now(false);
            this->player2_.set_is_playing_now(false);
            this->Update_statistics();
            return;
        }
        this->player1_.pull_card();
        this->player2_.pull_card();
        card_on+=2;
        // If you run out of cards after 2 face down cards have come out
        if(this->player1_.stacksize()==0){
            this->player2_.increase_cardes_Taken_(card_on/2);
            this->player2_.increase_cardes_Taken_(card_on/2);
            this->player1_.set_is_playing_now(false);
            this->player2_.set_is_playing_now(false);
            this->Update_statistics();
            return;
        }
        card_p1 = this->player1_.get_card();
        card_p2 = this->player2_.get_card();
        val_p1 = card_p1.get_value();
        val_p2 = card_p2.get_value();
        card_on+=2;

    }
    //A case where one of the players got 1
    if(val_p1==1){
        if (val_p2==2){
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
            this->player2_.increase_cardes_Taken_(card_on);


        } else{
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
            this->player1_.increase_cardes_Taken_(card_on);
        }

    }
    else if(val_p2==1){
        if (val_p1==2){
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
            this->player1_.increase_cardes_Taken_(card_on);
        } else{
            temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                           " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
            this->player2_.increase_cardes_Taken_(card_on);
        }

    }
    else if(val_p2<val_p1){
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                       " played " + card_p2.toString() + " - "+ this->player1_.getname()+" won.\n";
        this->player1_.increase_cardes_Taken_(card_on);
    }
    else if(val_p2>val_p1){
        temp_status += this->player1_.getname() + " played " + card_p1.toString() + ", " + this->player2_.getname() +
                       " played " + card_p2.toString() + " - "+ this->player2_.getname()+" won.\n";
        this->player2_.increase_cardes_Taken_(card_on);
    }
    this->player1_.pull_card();
    this->player2_.pull_card();
    this->status_lest_=temp_status;
    this->status_+=status_lest_;
    // Updates that the players have finished playing if necessary
    if(this->player1_.stacksize()==0){
        this->player1_.set_is_playing_now(false);
        this->player2_.set_is_playing_now(false);
        this->Update_statistics();
    }
}



void Game::printLastTurn() {
    cout<< this->status_lest_<<endl;
}

void Game::playAll() {
    while (this->player1_.stacksize()!=0){
        playTurn();
    }
    this->player1_.set_is_playing_now(false);
    this->player2_.set_is_playing_now(false);
}

void Game::printWiner() {
    if(this->player1_.stacksize()!=0){
        cout<<"The game is not over yet"<<endl;
        return;
    }
    if(this->player1_.cardesTaken()==this->player2_.cardesTaken()){
        cout<<"The game ended in a draw"<<endl;
        return;
    }
    if(this->player1_.cardesTaken()> this->player2_.cardesTaken()){
        cout<<"the winner is: "+ this->player1_.getname()<<endl;
    }else{
        cout<<"the winner is: "+ this->player2_.getname()<<endl;
    }
}

void Game::printLog() {
    cout<< this->status_<<endl;
}

void Game::printStats() {
    this->player1_.printStats_();
    this->player2_.printStats_();

}

void Game::Update_statistics(){
    if(this->cnt_Update_statistics==0){
        if (this->player1_.cardesTaken()== this->player2_.cardesTaken()){
            this->player1_.increase_draw();
            this->player2_.increase_draw();
        }
        else if(this->player1_.cardesTaken()> this->player2_.cardesTaken()){
            this->player1_.increase_win();
            this->player2_.increase_loss();
        }else{
            this->player2_.increase_win();
            this->player1_.increase_loss();
        }

        cnt_Update_statistics++;
    }
}
