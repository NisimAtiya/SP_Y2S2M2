//
// Created by Nisim Atiya on 22/03/2023.
//

#ifndef SP_Y2S2M2_NEW_CARD_HPP
#define SP_Y2S2M2_NEW_CARD_HPP
#include <string>

using namespace std;

namespace ariel{}
enum class suits{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};
enum class card_names{
    ACE=1,
    TOW,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
    JECK,
    QUEEN,
    KING
};
class Card {
    private:
        card_names name_;
        suits suits_;
        int value_;
    public:
        card(card_names name, suits suits, int value);
        int get_value();
        string toString();

};


#endif //SP_Y2S2M2_NEW_CARD_HPP
