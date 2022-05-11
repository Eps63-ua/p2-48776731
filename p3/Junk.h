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
