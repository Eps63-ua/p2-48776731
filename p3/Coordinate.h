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
        Coordinate(int row, int column); //constructor, iniciamos a -1
        int getRow() const; //devuelve valor fila, getters
        int getColumn() const; //devuelve valor columna, getters
        void setRow(int row); //modifica valor fila, setters
        void setColumn(int column); //modifica valor columna, setters
        bool compare(const Coordinate &coord) const; //compara coordenadas
    
    friend ostream& operator<<(ostream &os, const Coordinate &coord); //muestra coordenadas
};

#endif
        
        
    