#ifndef _COORDINATE_H
#define _COORDINATE_H

#include <iostream>
using namespace std;

class Coordinate{
    
    protected:
        int row;
        int column;
    public:
        Coordinate(int fila=-1, int columna=-1); //constructor, iniciamos a -1
        ~Coordinate();
        int getRow() const; //devuelve valor fila, getters
        int getColumn() const; //devuelve valor columna, getters
        void setRow(int fila); //modifica valor fila, setters
        void setColumn(int columna); //modifica valor columna, setters
        bool compare(const Coordinate &coord); //compara coordenadas
        friend ostream& operator<<(ostream &os, const Coordinate &coord); //muestra coordenadas
};

#endif
        
        
    