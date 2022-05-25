#ifndef _BETONSKI_H_
#define _BETONSKI_H_
/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
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