#include "Board.hpp"
using namespace pandemic; // Understood by Demo

int &Board::operator[](City city) // operator override
{
    return diseaseTracker[city];
}
 bool Board::is_clean() // Check if Board is clean - T/F
{
    return true;
}
ostream &pandemic::operator<<(ostream &out, const Board &board) // Operator Override
{
    return out;
}
void Board::remove_cures() // Just Does but Doesn't Return hence Void
{
}