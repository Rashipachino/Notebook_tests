#include <iostream>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;


namespace ariel{
    class Notebook {
        public:
            Notebook();
            void write(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, string msg);
            string read(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len);
            void erase(unsigned int page, unsigned int row, unsigned int col, ariel::Direction dir, unsigned int len);
            void show(unsigned int page);
    };
}