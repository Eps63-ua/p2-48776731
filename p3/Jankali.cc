/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#include "Jankali.h"

Jankali::Jankali(string name){
    
    if(name==" "){
        throw EXCEPTION_NAME;
    }
    
    this->name=name;
    power=300;
}

string Jankali::getName() const{
    return name;
}
        
int Jankali::getPower() const{
    return power;
}

void Jankali::hunt(vector<Betonski *betonskis>){
}

bool Jankali::setTrap(const Coordinate &coord){
}

void Jankali::spoil(){
}

void Jankali::spoil(typedef JunkType){
}

void Jankali::spoil(int pos){
}