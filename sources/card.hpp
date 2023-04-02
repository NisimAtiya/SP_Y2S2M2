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
        int value_;
        string Type_;

    public:
        Card(int value, string Type);
        int get_value();
        string toString();
        Card* bild_package();

};


#endif //SP_Y2S2M2_NEW_CARD_HPP
