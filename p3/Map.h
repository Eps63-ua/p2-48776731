#ifndef _MAP_H_
#define _MAP_H_

#include "Coordinate.h"
#include "Junk.h"

using namespace std;

class Map{
    
    protected:
        int row;
        int column;
        
    public:
        Map(int rows, int columns);
        bool inInside(const Coordinate &coord);
        void putJunk(const Junk &junk, const Coordinate &coord);
       // Junk
};

#endif
    
    