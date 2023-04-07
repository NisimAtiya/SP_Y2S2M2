//
// Created by Nisim Atiya on 22/03/2023.
//

#include "player.hpp"
#include "card.hpp"
#include <iostream>
using namespace std;



int Player::stacksize() {
    return this->packet.size();
}

int Player::cardesTaken() {
    return this->cardes_Taken_;
}


string Player::getname() {
    return this->name_;
}
void Player::set_name(string name) {
    this->name_ =name;
}
bool Player::is_playing_now() {
    return this->is_playing_now_;
}
void Player::set_is_playing_now(bool playing) {
    this->is_playing_now_ = playing;
}
void Player::set_cardesTaken(int num){
    this->cardes_Taken_=num;
}
Player::Player(string name) {
    set_name(name);
    set_is_playing_now(false);
    set_cardesTaken(0);
    this->played=0;
    this->win=0;
    this->loss=0;
    this->draw=0;

}
Player::Player() {
    set_name("guest");
    set_is_playing_now(false);
    set_cardesTaken(0);
    this->played=0;
    this->win=0;
    this->loss=0;
    this->draw=0;

}
void Player::take_card(Card c){
    this->packet.push_back(c);
}
Card Player::get_card(){
    return this->packet.back();
}
void Player::pull_card(){
    this->packet.pop_back();
}
void Player::increase_cardes_Taken_(int num){
    this->cardes_Taken_+=num;
}
void Player::increase_played(){
    this->played++;
}
void Player::increase_win(){
    this->win++;
}
void Player::increase_loss(){
    this->loss++;
}
void Player::increase_draw(){
    this->draw++;
}
void Player::printStats_(){
    cout<< getname() + " played: " + to_string(this->played) + " games, Won: " + to_string(this->win) + " games, lost: " + to_string(
            this->loss) + "games and ended in a draw: " + to_string(this->draw) + "games"<<endl;
}


