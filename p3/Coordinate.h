#ifndef _COORDINATE_H
#define _COORDINATE_H

#include <iostream>
using namespace std;

class Coordinate{
    
    protected:
        int row;
        int column;
    public:
        Coordinate();
        Coordinate(int row, int column); 
        int getRow() const; 
        int getColumn() const; 
        void setRow(int row); 
        void setColumn(int column); 
        bool compare(const Coordinate &coord) const; 
    
    friend ostream& operator<<(ostream &os, const Coordinate &coord); 
};

#endif
        
        
    