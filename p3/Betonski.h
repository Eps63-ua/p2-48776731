#ifndef _BETONSKI_H_
#define _BETONSKI_H_

#include "Coordinate.h"
#include "Junk.h"
#include "Map.h"
#include "Util.h"

#include <iostream>
#include <string.h>

using namespace std;

class Betonski{
    protected:
        string name;
        int anger;
        bool captured;
        vector<Junk> bag;
        Coordinate position;
    
    public:
        Betonski(string name);
        string getName() const;
        int getAnger() const;
        bool isCaptured() const;
        Coordinate getPosition() const;
        void capture();
        void setPosition(const Coordinate &cord);
        int calculateValue() const;
        int calculateValue(JunkType type) const;
        int spoliation();
        int spoliation(JunkType type);
        int extract(Map &map);
        bool move(const Map &map);
        
    friend ostream& operator<<(ostream &os, const Betonski &betonski);
};

#endif