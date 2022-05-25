/* Programación 2 - Práctica 3
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */
#include "Betonski.h"

using namespace std;


Betonski::Betonski(string name){
    if(name==""){
        throw EXCEPTION_NAME;
    }else{
        
        this->name=name;
        anger=0;
        captured=false;
    }
}

string Betonski::getName() const{
    return name;
}

int Betonski::getAnger() const{
    return anger;
}

bool Betonski::isCaptured() const{
    return captured;
}

Coordinate Betonski::getPosition() const{
   return position;
}

void Betonski::capture(){
    captured=true;
}

void Betonski::setPosition(const Coordinate &coord){
    position.setRow(coord.getRow());
    position.setColumn(coord.getColumn());
}

int Betonski::calculateValue() const{

    int value=0;
    
    for(unsigned int y=0; y<bag.size(); y++){
        value=value+bag[y].getValue();
    }
    
    return value;
}

int Betonski::calculateValue(JunkType type) const{

    int value=0;
    
    for(unsigned int y=0; y<bag.size(); y++){
        if((type==bag[y].getType()) ){
            value=value+bag[y].getValue();
        }
    }
    
    return value; 
}
    
int Betonski::spoliation(){
    
    int recursos=0;
    
    if(!captured){
        throw BETONSKI_NOT_CAPTURED;
    }else{
        
        for(unsigned int y=0; y<bag.size(); y++){
            recursos=recursos+bag[y].getValue();
           //recursos=calculateValue(bag[y].getType());
        }
        anger=anger+recursos;
        
        if(anger>5000){
            anger=0;
            captured=false;
            
            throw EXCEPTION_REBELION;
        }else{
            bag.clear();
        }
    }
    return recursos;
}

int Betonski::spoliation(JunkType type){
    
    int recursos=0;
    anger=anger+calculateValue(type);
     if(!captured){
        throw BETONSKI_NOT_CAPTURED;
    }else{
        for(unsigned int y=0; y<bag.size(); y++){
            if((type==bag[y].getType()) ){
                recursos=recursos+bag[y].getValue();
            
                if(anger>5000){
                    anger=0;
                    captured=false;
                    
                    throw EXCEPTION_REBELION;
                }else{
                    bag.erase(bag.begin()+y);
                    y--;
                }
            }
        }
    }
    return recursos;
}

int Betonski::extract(Map &map){
    int valor;
    Junk aux;
    
    if(map.isInside(position)){
        aux=map.collectJunk(position);
    }
    
    valor=aux.getValue();
    
    if(valor!=0){
        bag.push_back(aux);
    }
    return valor;
}
        
bool Betonski::move(const Map &map){
    
    int num;
    bool dentro;
    
    Util aux;
    Coordinate newpos; 
    
    if(map.isInside(position)){
        num=aux.getRandomNumber(8);
        
        switch(num){
            case 0:
                newpos.setRow((position.getRow()-1));
                newpos.setColumn((position.getColumn()));
                break;
            case 1:
                newpos.setRow((position.getRow()-1));
                newpos.setColumn((position.getColumn()+1));
                break;
            case 2:
                newpos.setRow((position.getRow()));
                newpos.setColumn((position.getColumn()+1));
                break;
            case 3:
                newpos.setRow((position.getRow()+1));
                newpos.setColumn((position.getColumn()+1));
                break;
            case 4:
                newpos.setRow((position.getRow()+1)); 
                newpos.setColumn((position.getColumn()));
                break;
            case 5:
                newpos.setRow((position.getRow()+1));
                newpos.setColumn((position.getColumn()-1));
                break;
            case 6:
                newpos.setRow((position.getRow()));
                newpos.setColumn((position.getColumn()-1));
                break;
            case 7:
                newpos.setRow((position.getRow()-1));
                newpos.setColumn((position.getColumn()-1));
                break;
                
        }
    }else{
        throw EXCEPTION_OUTSIDE;
    }
    
    dentro=map.isInside(newpos);
    
    if(dentro){
        position.setRow(newpos.getRow());
        position.setColumn(newpos.getColumn());
        return true;
    }else{
        return false;
    }
}
        
ostream& operator<<(ostream &os, const Betonski &betonski){
    os<<"Betonski "<<'"'<<betonski.name<<'"';
    if(betonski.captured){
        os<<" Captured ";
    }else{
        os<<" Free ";
    }
    os<<betonski.anger<<betonski.position<<endl;
    
    if(betonski.bag.size()==0){
        os<<endl;
    }else{
        for(unsigned int y=0; y<betonski.bag.size(); y++){
            string tipo;
    
            switch(betonski.bag[y].getType()){
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
            
            os << "[" << tipo << ":" << betonski.bag[y].getQuantity() << "]" << endl; 
        }
    }
    return os;
}
















