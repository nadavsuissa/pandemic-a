#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("Board Test")
{
    Board board;
    
    Board board1;
    board1[City::LosAngeles] = 3;
    board1[City::Bogota] = 1;
    board1[City::Tokyo] = 2;
    CHECK(board1.is_clean() == false);
    CHECK_NE(board1[City::LosAngeles], board1[City::Bogota]);
    CHECK_EQ(board1[City::Tokyo], board1[City::Tokyo]);
    board1.remove_cures();
    CHECK(board1.is_clean() == true);
}
TEST_CASE("Scientist and Basic Player Functionality Tests")
{
    Board board;
    board[City::Paris] = 3;
    board[City::Milan] = 1;
    board[City::Essen] = 2;

    Scientist player{board, City::Paris, 2}; 
    player.take_card(Milan);
    player.take_card(Milan);


    CHECK_NOTHROW(player.drive(Milan));
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.discover_cure(Color::Blue));


        Board board1;
    board1[City::Paris] = 3;
    board1[City::Milan] = 1;
    board1[City::Essen] = 2;

    Scientist player1{board1, City::Paris, 2}; 
    player1.take_card(Milan);
    


    CHECK_NOTHROW(player.drive(Milan));
    CHECK_NOTHROW(player.build());
    CHECK_THROWS(player.discover_cure(Color::Blue));
    
}
TEST_CASE("OperationsExpert Functionality")
{
    Board board;
    board[City::LosAngeles] = 3;
    board[City::Bogota] = 1;
    board[City::Tokyo] = 2;

    OperationsExpert player{board, City::LosAngeles}; 
    player.take_card(Montreal);
    player.take_card(London);
    player.take_card(Delhi);

    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.drive(MexicoCity));
    CHECK_THROWS(player.drive(LosAngeles));
    CHECK_NOTHROW(player.treat(Montreal));
    CHECK_THROWS(player.treat(Madrid));
    CHECK_NOTHROW(player.fly_direct(London));
    CHECK_THROWS(player.drive(Paris));
    CHECK_NOTHROW(player.build());
}

TEST_CASE("Dispatcher Functionality")
{
    Board board;
    board[City::NewYork] = 3;
    board[City::Montreal] = 1;
    board[City::London] = 2;
    board[City::Madrid] = 2;

    Dispatcher player{board, City::NewYork}; 
    player.take_card(Montreal);
    player.take_card(HongKong);
    player.take_card(NewYork);
    player.take_card(Delhi);

    CHECK_THROWS(player.fly_direct(Madrid));
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_direct(HongKong));
    CHECK_NOTHROW(player.fly_direct(London));
    CHECK_NOTHROW(player.fly_direct(Madrid));
    

}


