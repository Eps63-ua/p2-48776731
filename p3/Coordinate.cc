/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
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
    
    if((column==coord.column) && (row==coord.row)){
        return true;
        
    }else{
        return false;
    }
}    


ostream& operator<<(ostream &os, const Coordinate &coord){
    os << "[" << coord.row << "," << coord.column << "]" << endl;
    return os;
}


