//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_CARD_HPP
#define SP_Y2S2M2_NEW_CARD_HPP
#include <string>

using namespace std;

namespace ariel{}

class Card {
    private:
        string name_;
        string suits_;
        int value_;
    public:
        Card(string name, string suits, int value);
        int get_value();
        string toString();
        Card* bild_package();

};


#endif //SP_Y2S2M2_NEW_CARD_HPP
