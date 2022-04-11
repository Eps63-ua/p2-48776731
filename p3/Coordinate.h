#include <iostream>
using namespace std;

class Coordinate{
    
    protected:
        int row;
        int column;
    public:
        Coordinate(int prow=-1, int pcolumn=-1); //constructor, iniciamos a -1
        int getRow() const; //devuelve valor fila, getters
        int getColumn() const; //devuelve valor columna, getters
        void setRow(int prow); //modifica valor fila, setters
        void setColumn(int pcolumn); //modifica valor columna, setters
        bool compare(const Coordinate &coord); //compara coordenadas
        friend ostream& operator<<(ostream &os, const Coordinate &coord); //muestra coordenadas
}
        
        
    