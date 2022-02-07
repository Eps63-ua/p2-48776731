/* Programación 2 - Práctica 1
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 * seed = 333
 */
#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include <cstring> //para str()

using namespace std;

const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200;
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp;
};

enum Breed{
  AXOLOTL,
  TROLL,
  ORC,
  HELLHOUND,
  DRAGON
};

struct Enemy{
  Breed name;
  Core features;
};

struct Hero{
  char name[KNAME];
  Core features;
  bool special;
  int runaways;
  int exp;
  int kills[KENEMIES];
};

typedef char Tcadena[KNAME];

int rollDice(){
  return rand()%KDICE+1;
}

Hero createHero(){
    Tcadena name;
    Hero Hero;
    int attack_points=0, defense_points=0, hp_points=0; 
    float attack_percent=0, defense_percent=0;
    bool sum=false;
    
    cout<<"Enter hero name: ";
    cin>>name; 
    strcpy(Hero.name, name);
    
    //comprobar que el nombre es valido
    
    while(!sum || attack_percent==0 || defense_percent==0){
        cout<<"Enter attack/defense: ";
        cin>>attack_percent>>defense_percent;
        
        if((attack_percent+defense_percent)==100){
            sum=true;
        }
    }
    
    attack_points = (attack_percent/100)*KPOINTS;
    defense_points = (defense_percent/100)*KPOINTS;
    
    hp_points = defense_points*2;
         
         
}

Enemy createEnemy(int rollDice){
    Enemy Enemy;
    int result;
    
   result = rollDice;
    
    if(result<=1){
        
        Enemy.name = AXOLOTL;
        Enemy.features.attack = 40;
        Enemy.features.defense = 40;
        Enemy.features.hp = Enemy.features.defense*2;
        
    }else if(result<=11){
        
        Enemy.name = TROLL;
        Enemy.features.attack = 60;
        Enemy.features.defense = 80;
        Enemy.features.hp = Enemy.features.defense*2;
        
    }else if(result<=15){
        
        Enemy.name = ORC;
        Enemy.features.attack = 80;
        Enemy.features.defense = 120;
        Enemy.features.hp = Enemy.features.defense*2;
        
    }else if(result<=18){
        
        Enemy.name = HELLHOUND;
        Enemy.features.attack = 120;
        Enemy.features.defense = 100;
        Enemy.features.hp = Enemy.features.defense*2;
        
    }else{
        
        Enemy.name = DRAGON;
        Enemy.features.attack = 160;
        Enemy.features.defense = 140;
        Enemy.features.hp = Enemy.features.defense*2;
    }
    
    cout<< Enemy.name << endl
    << Enemy.features.attack << endl
    << Enemy.features.defense << endl
    << Enemy.features.hp << endl;
    

} 

void fight(Hero &hero,Enemy &enemy){
}

void report(const Hero &hero){
}

void showMenu(){
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}

int main(int argc,char *argv[]){
  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    // Aquí vendrá todo tu código del "main"...
     int dicenumber = rollDice();
    createEnemy(dicenumber);
    createHero();
  }
}
