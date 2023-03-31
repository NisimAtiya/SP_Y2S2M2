//
// Created by Nisim Atiya on 22/03/2023.
//

#include "card.hpp"
#include <iostream>
#include <string>
using namespace std;
Card::Card(string name, string suits, int value) {
    this->name_=name;
    this->suits_=suits;
    this->value_=value;
}

int Card::get_value() {
    return this->value_;
}
string Card::toString() {
    return this->name_ + " of " + this->suits_;
}