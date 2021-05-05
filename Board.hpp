#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>
using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        map<City, int> diseaseTracker;

    public:
        Board() {}
        int &operator[](City city);
       static bool is_clean();

        friend std::ostream &operator<<(std::ostream &out, const Board &board);
        void remove_cures();
    };
}