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

int Card::get_value() {
    return this->value_;
}
string Card::toString() {
    return to_string(this->value_) + " of " + this->Type_;
}
Card* Card::bild_package(){
    Card temp [52];
    int index=0;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if(i==1){
                temp[index] Card(j,"CLUB");
            }
            else if(i==2){
                temp[index] Card(j,"DIAMOND");
            }
            else if(i==3){
                temp[index] Card(j,"HEART");
            }
            else{
                temp[index] Card(j,"SPADE");

            }
        }

    }
    return temp;
}