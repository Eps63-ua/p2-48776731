#include "Coordinate.h"
#include <iostream>
using namespace std;

Coordinate::Coordinate(){
    row=column=-1;
}

Coordinate::Coordinate(int row, int column){
    this->row=row;
    this->column=column;
}


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

bool Coordinate::compare(const Coordinate &coord) const{
    bool igual=false;
    
    if((column==coord.column) && (row==coord.row)){
        igual=true;
    }    
        return igual;
}    


ostream& operator<<(ostream &os, const Coordinate &coord){
    os << "[" << coord.row << "," << coord.column << "]" << endl;
    return os;
}


