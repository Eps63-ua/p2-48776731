/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#ifndef _JANKALI_H
#define _JANKALI_H

#include "Coordinate.h"
#include "Junk.h"
#include "Map.h"
#include "Util.h"

#include <iostream>

using namespace std;

class Jankali{
    private:
        string name;
        int power;
        vector<Betonski> subdued;
        vector<Coordinate> traps;
    public:
        Jankali(string name);
        string getName() const;
        int getPower() const;
        void hunt(vector<Betonski *betonskis>);
        bool setTrap(const Coordinate &coord);
        void spoil();
        void spoil(typedef JunkType);
        void spoil(int pos);
        
    friend ostream& operator<<(ostream &os, const Jankali &jankali);
};

#endif