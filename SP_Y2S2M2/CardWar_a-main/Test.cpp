//
// Created by Nisim Atiya on 22/03/2023.
//

#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>

TEST_CASE("Test: 1"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    //Checks if a game starts properly
    CHECK(p1.cardesTaken()==0);
    CHECK(p1.cardesTaken()==0);
    CHECK(p1.stacksize()==25);
    CHECK(p2.stacksize()==25);
    //Checks that the playTurn function works and does not throw errors
    CHECK_NOTHROW(game.playTurn());
    game.playTurn();
    game.playTurn();
    //Checks after three turns each player has 22 cards in the pack
    CHECK(p1.stacksize()==22);
    CHECK(p2.stacksize()==22);
    //Checks that the playAll function works and then checks that an error is thrown when trying to run the game again after it has ended
    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playAll());


}
TEST_CASE("Test: 2") {
    Player p1("Alice");
    //Checks that an error is thrown when another player tries to play with himself
    CHECK_THROWS(Game (p1, p1));

    Player p2("Bob");
    //Checks that the normal constructor works
    CHECK_NOTHROW(Game (p1, p2));

    Player p3("Carol");
    //Checks that an error is thrown if a player already playing tries to enter another game
    CHECK_THROWS(Game (p1, p3));

}
TEST_CASE("Test: 3") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    //Checks whether an error is thrown when trying to view game history using the printLog and printStats functions before starting a round
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printStats());
    game.playTurn();
    //Checks the printLog and printStats functions after running one round
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLog());
    //Checks that an error is thrown when the printWiner function is used before the game ends
    CHECK_THROWS(game.printWiner());

    game.playAll();
    //Checks that after the game is over that both players have no cards left in the pack
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    //Checks the printWiner function
    CHECK_NOTHROW(game.printWiner());



}