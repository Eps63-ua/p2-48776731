#ifndef _MAP_H_
#define _MAP_H_

using namespace std;

class Map{
    
    private:
        int row;
        int column;
        
    public:
        Map(int rows, int columns);
        bool inInside(const Coordinate &coord);
        void putJunk(const Junk &junk, const Coordinate &coord);
       // Junk
};

#endif
    
    