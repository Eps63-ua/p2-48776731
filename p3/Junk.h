#ifndef _JUNK_H
#define _JUNK_H

using namespace std;

class Junk{
private:
    int quantity;
    typedef JunkType;
public:
    Junk(typedef JunkType, int quantity);
    Junk();
    JunkType getType() const;
    int getQuantity() const;
    char getTypeChar() const;
    int getValue() const;
    //friend ostream& operator<<(ostream &os, const
};

#endif
