#pragma once
#include "Board.hpp"
#include <string>
using namespace std;

namespace pandemic
{
    class Player
    {
    private:
        string job;
        City city;
        
        Board board;

    public:
        Player(Board &recievedb, City recievedc, std::string recievedj) // Constructor...
        {
            board = recievedb; // REcieved Board
            city = recievedc;  // Recieved City
            job = recievedj;   // Recieved Job
        }
        virtual Player &discover_cure(Color color); // Name Based Demo
        virtual Player &fly_direct(City city); // Name Based Demo

        Player &fly_shuttle(City city);
        virtual Player &treat(City city);
        Player &drive(City city);
        string role()
        {
            return job;
        }
        virtual Player &build();
        Player &take_card(City city);
        Player &fly_charter(City city);
    };
}