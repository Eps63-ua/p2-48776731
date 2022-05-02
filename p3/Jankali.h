#ifndef _JANKALI_H
#define _JANKALI_H

#include <iostream>

using namespace std;

class Jankali{
    private:
        string name;
        int power;
    public:
        Jankali(string name);
        string getName() const;
        int getPower() const;
        //void hunt(vector<Betonski *betonskis>);
        void spoil();
        void spoil(typedef JunkType);
        void spoil(int pos);
        //friend
};

#endif