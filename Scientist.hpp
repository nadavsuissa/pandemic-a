#include "Player.hpp"
namespace pandemic {
class Scientist : public Player {
    private:
        int numofCArds;
    public:
        Scientist(Board& b, City c, int n): Player(b, c, "Scientist") // Here we define n(in real game default 4) n - number ofmoves to reveal cure 
        {
            numofCArds = n;
        }
        Player& discover_cure(Color color) override;
};
}