/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#ifndef _MAP_H_
#define _MAP_H_

#include "Coordinate.h"
#include "Junk.h"

#include <vector>

using namespace std;

class Map{
    
    friend ostream& operator<<(ostream &os, const Map &map);
    
    protected:
        int rows;
        int columns;
        vector<vector<Junk> > junks;
        
    public:
        Map(int rows, int columns);
        bool isInside(const Coordinate &coord) const;
        void putJunk(const Junk &junk, const Coordinate &coord);
        Junk getJunk(const Coordinate &coord) const;
        Junk collectJunk(const Coordinate &coord);
        
};

#endif
    
    