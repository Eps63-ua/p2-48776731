/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#include "Jankali.h"
#include <vector>
#include <string.h>

Jankali::Jankali(string name){
    
    if(name==""){
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

void Jankali::hunt(vector<Betonski*> betonskis){
    
    Coordinate posBet;
    bool trampa=false;
    
    for(unsigned int j=0; j<betonskis.size(); j++){
        posBet=betonskis[j]->getPosition();
        
        for(unsigned int i=0; i<traps.size() && !trampa; i++){
            if(posBet.compare(traps[i]) && !betonskis[j]->isCaptured() ){
                trampa=true;
                betonskis[j]->capture();
                subdued.push_back(betonskis[j]);
            }
        }
        
        trampa=false;
    }
}

bool Jankali::setTrap(const Coordinate &coord){
    int coste=0;
    bool trampa=false; 
    
    coste=(coord.getRow()+2)*(coord.getColumn()+2);
    
    if(traps.size()==0){
        
        if(power<coste){
                trampa=false; 
            }else{
                traps.push_back(coord);
                power=power-coste;
                trampa=true;
            }
    }else{
        for(unsigned int i=0; i<traps.size() && !trampa; i++){
            
            if(coord.compare(traps[i]) || power<coste){
                trampa=false; 
            }else{
                traps.push_back(coord);
                power=power-coste;
                trampa=true;
            }
        }
        
    }
    if(trampa){
        return true;
    }else{
        return false;
    }
}

void Jankali::spoil(){
    for(unsigned int i=0; i<subdued.size(); i++){
        try{
            power=power+subdued[i]->spoliation();
        }catch(...){
            subdued.erase(subdued.begin()+i);
        }
    }
}

void Jankali::spoil(JunkType type){
    for(unsigned int i=0; i<subdued.size(); i++){
        try{
            power=power+subdued[i]->spoliation(type);
        }catch(...){
            subdued.erase(subdued.begin()+i);
        }
    }
}

void Jankali::spoil(int pos){
    
    if(pos>0 && unsigned(pos)<subdued.size()){
        try{
            power=power+subdued[pos]->spoliation();
        }catch(...){
            subdued.erase(subdued.begin()+pos);
        }
    }
}

ostream& operator<<(ostream &os, const Jankali &jankali){
    os<<"Jankali "<<'"'<<jankali.name<<'"'<<jankali.power<<endl;
    
    for(unsigned int i=0; i<jankali.subdued.size(); i++){
        os<<Betonski(*jankali.subdued[i]);
    }
    
    os<<"Traps ";
    
    for(unsigned int i=0; i<jankali.traps.size(); i++){
        os<<jankali.traps[i];
    }
    os<<endl;
    
    return os;
}