#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate::Coordinate(int fila, int columna){
    row=fila;
    column=columna;
}

Coordinate::~Coordinate(){}

int Coordinate::getRow() const{
    return row;
}

int Coordinate::getColumn() const{
    return column;
}

void Coordinate::setRow(int row){
    this->row=row;
}

void Coordinate::setColumn(int column){
    this->column=column;
}

bool Coordinate::compare(const Coordinate &coord) {
    bool igual=false;
    
    if((this->getColumn()==coord.getColumn()) && (this->getRow()==coord.getRow())){
        igual=true;
    }    
        return igual;
}    


ostream& operator<<(ostream &os, const Coordinate &coord){
    os << "[" << coord.row << "," << coord.column << "]" << endl;
    return os;
}


