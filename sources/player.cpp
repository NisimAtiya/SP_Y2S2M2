//
// Created by Nisim Atiya on 22/03/2023.
//

#include "player.hpp"
#include "card.hpp"

int Player::id=1;

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
    this->id_=id;
    id++;
}
Player::Player() {
    set_name("guest");
    set_is_playing_now(false);
    set_cardesTaken(0);
    this->id_=id;
    id++;
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

int Player::getid(){
    return this->id_;
}