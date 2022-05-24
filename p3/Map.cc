/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#include "Map.h"
#include "Coordinate.h"
#include "Junk.h"

#include <vector>
#include <string.h>

using namespace std;

Map::Map(int rows, int columns){
    
    
    if(rows<5 || columns<5){
        throw EXCEPTION_SIZE;
    }else{
        this->rows=rows;
        this->columns=columns;
        
        Junk junk;
        vector<Junk> Junks;
        
        for(int i=0; i<this->columns; i++){
        Junks.push_back(junk);
        }
    
        for(int i=0; i<this->rows; i++){
            junks.push_back(Junks);
        }
    }
}


bool Map::isInside(const Coordinate &coord) const{
    if((coord.getRow()<0 || coord.getColumn()<0)){
        return false;
    }else if(coord.getRow()>=rows || coord.getColumn()>=columns){
        return false;
    }else{
        return true;
    }
}

void Map::putJunk(const Junk &junk, const Coordinate &coord){
    
    if(isInside(coord)==false){
        throw EXCEPTION_OUTSIDE;
    }else{
        junks[coord.getRow()][coord.getColumn()]=junk;
    }
}
        
Junk Map::getJunk(const Coordinate &coord) const{
    
    if(isInside(coord)==false){
        throw EXCEPTION_OUTSIDE;
    }else{
        return junks[coord.getRow()][coord.getColumn()];
    }
}
        
Junk Map::collectJunk(const Coordinate &coord){
    
    if(isInside(coord)==false){
        throw EXCEPTION_OUTSIDE;
    }else{
        Junk aux = junks[coord.getRow()][coord.getColumn()];
        
        Junk junk; 
        junks[coord.getRow()][coord.getColumn()]=junk;
        
        return aux;
    }
}

ostream& operator<<(ostream &os, const Map &map){
    
    os<<"  ";
    
    for(int i=0; i<map.columns; i++){
        if(i<10){
            os<<" 0"<<i;
        }else{
            os<<" "<<i;
    
        }
    }
    
    os<<endl;
    
    for(int i=0; i<map.rows; i++){
        if(i<10){
            os<<"0"<<i;
        }else{
            os<<i;
        }
            
        for(int j=0; j<map.columns; j++){
            Junk tipoJunk;
            tipoJunk=map.junks[i][j];
            if(tipoJunk.getTypeChar()=='W'){
                os<<"  ";
            }else{
                os<<" "<<tipoJunk.getTypeChar();
            }
        }
        os<<endl;
    }
    return os;
}