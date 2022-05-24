/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#include "Junk.h"
#include <iostream>
#include <string.h>

using namespace std;

Junk::Junk(){
    type= WASTELAND;
    quantity=0;    
}
    
Junk::Junk(JunkType type, int quantity){    
    
    if(quantity<0){
        throw EXCEPTION_QUANTITY;
    }else{
        this->type=type;
        this->quantity=quantity;
    }
}

JunkType Junk::getType() const{
    return type;
}
        
int Junk::getQuantity() const{
    return quantity;
}

char Junk::getTypeChar() const{
    char letra;
    
    switch(type){
        case WASTELAND:
            letra='W';
            break;
        case GOLD:
            letra='G';
            break;
        case METAL:
            letra='M';
            break;
        case FOOD:
            letra='F';
            break;
        case STONE:
            letra='S';
            break;
    }   
    
    return letra;
}

int Junk::getValue() const{

    int valorTipo, value;
    
    switch(type){
        case WASTELAND:
            valorTipo=0;
            break;
        case GOLD:
            valorTipo=500;
            break;
        case METAL:
            valorTipo=100;
            break;
        case FOOD:
            valorTipo=50;
            break;
        case STONE:
            valorTipo=20;
            break;
    }
    
    value=valorTipo*quantity;
    
    return value;
}

ostream& operator<<(ostream &os, const Junk &junk){
    
    string tipo;
    
    switch(junk.type){
        case WASTELAND:
            tipo="WASTELAND";
            break;
        case GOLD:
            tipo="GOLD";
            break;
        case METAL:
            tipo="METAL";
            break;
        case FOOD:
            tipo="FOOD";
            break;
        case STONE:
            tipo="STONE";
            break;
    }
    
    os << "[" << tipo << ":" << junk.quantity << "]" << endl;
    return os;
}