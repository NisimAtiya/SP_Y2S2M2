//
// Created by Nisim Atiya on 22/03/2023.
//

#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;
Card::Card(int value, string Type) {
    this->Type_=Type;
    this->value_=value;
}
Card::Card() {
    this->Type_="None";
    this->value_=0;
}

int Card::get_value() {
    return this->value_;
}
string Card::get_type() {
    return this->Type_;
}
void Card::set_value(int value) {
    this->value_=value;
}
void Card::set_type(string Type) {
    this->Type_=Type;

}
string Card::toString() {
    return to_string(get_value()) + " of " + get_type();
}

