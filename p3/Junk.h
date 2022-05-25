/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#ifndef _JUNK_H
#define _JUNK_H

#include "Util.h"
#include <iostream>

using namespace std;

class Junk{
    
    friend ostream& operator<<(ostream &os, const Junk &junk);
    
    protected:
        int quantity;
        JunkType type;
   
    public:
        Junk();
        Junk(JunkType type, int quantity);
        JunkType getType() const;
        int getQuantity() const;
        char getTypeChar() const;
        int getValue() const;
};

#endif
