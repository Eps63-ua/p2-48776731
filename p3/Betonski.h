#ifndef _BETONSKI_H_
#define _BETONSKI_H_

#include <iostream>

using namespace std;

class Betonski{
    private:
        string name;
        int anger;
        bool captured;
    
    public:
        Betonski(string name);
        string getName() const;
        int getAnger() const;
        bool isCaptured() const;
        Coordinate getPosition() const;
        void capture();
        //void setPosition
        int calculateValue() const;
        int calculateValue(typedef JunkType) const;
};

#endif