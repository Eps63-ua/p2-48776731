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

enum Breed{ //estas palabras se convierten automaticamente en su valor numerico de 0 a 4, lista
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
  int kills[KENEMIES-1];
};

typedef char Tcadena[KNAME];

int rollDice();
Hero createHero();
void check_name(Hero& hero);
Enemy createEnemy();
void showMenu(char&option, Hero& hero, Enemy& enemy, bool runaway, bool& special_attack);
void Runaway(bool& runaway, Hero& hero, Enemy& enemy, bool special_attack);
void fight(Hero& hero, Enemy& enemy, bool runaway, bool special_attack);
void report(const Hero& hero);

int rollDice(){
  return rand()%KDICE+1;
}

Hero createHero(){

    char barra;
    float attack_percent=0, defense_percent=0;
    bool sum=false;
    Hero hero;

    cout<<"Enter hero name:";
    cin.getline(hero.name, KNAME-1, '\n');
    
    check_name(hero);
    
    cout<<"Enter attack/defense:";
        cin>>attack_percent>>barra>>defense_percent;

    if((attack_percent+defense_percent)==100){
            sum=true;
        }

    while(!sum || attack_percent==0 || defense_percent==0 ){ //pedimos % de los valores de ataque y defenssa y comprobamos q son validos

        cout<<"ERROR: wrong distribution"<<endl;
        cout<<"Enter attack/defense:";
        cin>>attack_percent>>barra>>defense_percent;

        if((attack_percent+defense_percent)==100){
            sum=true;
        }
    }

    hero.features.attack = (attack_percent/100)*KPOINTS;
    hero.features.defense = (defense_percent/100)*KPOINTS;
    hero.features.hp = hero.features.defense*2;

    hero.runaways = 3;
    hero.special = true;
    hero.exp = 0;

    for(int i=0; i<KENEMIES; i++){
        hero.kills[i] = 0;
    }
    
    return hero;
}

void check_name(Hero& hero){
    
    bool wrong = false;
        
    if (not(isalpha(hero.name[0]))){ //comprueba primer digito es igual a letra
        cout<<"ERROR: wrong name1"<<endl;
        wrong = true;
    }
       
    if(wrong){
        cout<<"Enter hero name1:"<<endl;
        cin.getline(hero.name, KNAME-1, '\n');
        check_name(hero);
    }
    
    wrong = false; 
    
    for(int i=1; i<KNAME && hero.name[i]!='\0'; i++){
        if(not(isalnum(hero.name[i]))&& hero.name[i]!=' '){
            cout<<"ERROR: wrong name2"<<endl;
            i = KNAME;
            wrong = true;
        }
    }
    
     if(wrong){
        cout<<"Enter hero name2:";
        cin.getline(hero.name, KNAME-1, '\n');
        check_name(hero);
    }
}

Enemy createEnemy(){

    int result;
    Enemy enemy;

   result = rollDice();

    if(result<=6){

        enemy.name = AXOLOTL;
        enemy.features.attack = 40;
        enemy.features.defense = 40;
        enemy.features.hp = enemy.features.defense*2;

    }else if(result<=11){

        enemy.name = TROLL;
        enemy.features.attack = 60;
        enemy.features.defense = 80;
        enemy.features.hp = enemy.features.defense*2;

    }else if(result<=15){

        enemy.name = ORC;
        enemy.features.attack = 80;
        enemy.features.defense = 120;
        enemy.features.hp = enemy.features.defense*2;

    }else if(result<=18){

        enemy.name = HELLHOUND;
        enemy.features.attack = 120;
        enemy.features.defense = 100;
        enemy.features.hp = enemy.features.defense*2;

    }else{

        enemy.name = DRAGON;
        enemy.features.attack = 160;
        enemy.features.defense = 140;
        enemy.features.hp = enemy.features.defense*2;
    }

    cout<<endl<<"[Enemy]"<<endl;

    switch(enemy.name){
        case 0: cout<<"Breed: Axolotl"<<endl;
            break;
        case 1: cout<<"Breed: Troll"<<endl;
            break;
        case 2: cout<<"Breed: Orc"<<endl;
            break;
        case 3: cout<<"Breed: Hellhound"<<endl;
            break;
        case 4: cout<<"Breed: Dragon"<<endl;
            break;
    }
    cout<<"Attack: "<< enemy.features.attack << endl
    <<"Defense: "<< enemy.features.defense << endl
    <<"Health points: "<< enemy.features.hp << endl<<endl;
    
    return enemy;

}

void showMenu(char& option, Hero& hero, Enemy& enemy, bool runaway, bool& special_attack){

    bool valid;

    cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";

       cin>>option;

    if(option=='q'){
        valid = true;
    }else if(option == '1' || option == '2' || option == '3' || option == '4' ){
        valid = true;
    }else{
        valid = false;
    }

    while(!valid){
        cout << "ERROR: wrong option"<<endl
             << "[Options]" << endl
             << "1- Fight" << endl
             << "2- Run away" << endl
             << "3- Special" << endl
             << "4- Report" << endl
             << "q- Quit" << endl
             << "Option: ";
       cin>>option;
       //cout<<option<<endl;

       if(option=='q'){
            valid = true;
       }else if(option == '1' || option == '2' || option == '3' || option == '4' ){
            valid = true;
       }else{
            valid = false;
       }
    }
    
    cout<<endl;
    
    switch(option){
        case '1': fight(hero, enemy, runaway, special_attack);
            break;
            
        case '2': Runaway(runaway, hero, enemy, special_attack);
            break;
            
        case '3': 
            if(hero.special == true){
                special_attack = true;
                fight(hero, enemy, runaway, special_attack);
                // hero.special = false;
            }else{
                cout<<"ERROR: special not available"<<endl;
                showMenu(option, hero, enemy, runaway, special_attack);
            }
            break;
            
        case '4': report(hero);
                  fight(hero, enemy, runaway, special_attack);
            break;
            
        case 'q': 
            break;
    }
    
}

void Runaway(bool& runaway, Hero& hero, Enemy& enemy, bool special_attack){
    
    bool conditional; 
    char option;
    
        if(runaway == true){
                        
            conditional = false;
            runaway = false;
                    
        }else{
                    
            conditional = true;
        }
                    
        if(hero.runaways > 0 && conditional){
            
            cout << "You run away" << endl;
            
            hero.runaways--;
            runaway = true; 
            
            createEnemy();
            showMenu(option, hero, enemy, runaway, special_attack);
                        
        }else /*if(!conditional || hero.runaways == 0)*/{
                        
            cout<< "ERROR: cannot run away" << endl;
            showMenu(option, hero, enemy, runaway, special_attack);
        }
    
}

void fight(Hero &hero,Enemy &enemy, bool runaway, bool special_attack){ //hacer llamada recursiva hasta q el heroe muera

    int hit_points=0, dicenumber_attack=0, dicenumber_defense=0, dicenumber;
    char option; 
    
    //ataca el heroe
    
    if(special_attack){
        dicenumber_attack = 3*5*(rand()%KDICE+1); 
        hero.special = false;
    }else{
        dicenumber_attack = 5*(rand()%KDICE+1);
    }
    
    dicenumber_defense = 5*(rand()%KDICE+1);
    
    hit_points = (hero.features.attack + dicenumber_attack) - (enemy.features.defense +dicenumber_defense); 
    
    if(hit_points<0){
        hit_points = 0;
     }
   
    enemy.features.hp = enemy.features.hp - hit_points;
      
    cout<< endl <<"Hero -> Enemy" << endl
    << "Attack: " << hero.features.attack << " + " 
    << dicenumber_attack << endl
    << "Defense: " << enemy.features.defense << " + "
    << dicenumber_defense << endl
    << "Hit points: " << hit_points << endl;
    
    if(enemy.features.hp >= 0){
        
        cout << "Enemy health points: " << enemy.features.hp << endl << endl;
        
    }else{
        
        cout << "Enemy health points: 0" << endl << endl;
    }
    
    if(enemy.features.hp <= 0){
        
        cout<<"<<<<<<<<<<<<<<<<<<<<<Enemy killed>>>>>>>>>>>>>>>>>>>>>"<<endl;
        
        switch(enemy.name){
            case 0: hero.exp= hero.exp + 100;
                break;
            case 1: hero.exp= hero.exp + 150;
                break;
            case 2: hero.exp= hero.exp + 200;
                break;
            case 3: hero.exp= hero.exp + 300;
                break;
            case 4: hero.exp= hero.exp + 400;
                break;
        }
        
        hero.kills[enemy.name]++;
        
        for(int i=0; i<KENEMIES; i++){
            cout<<" "<<hero.kills[i]<<" ";
        }
        
        cout<<endl;
        
        cout<< "Hero exp points= "<<hero.exp<<endl;
        
        createEnemy(); // se crea un nuevo enemigo
        fight(hero, enemy, runaway, special_attack); //llamada recursiva
        
    }else{
        
        //ataca el enemigo
        
        dicenumber_attack = 5*(rand()%KDICE+1);
        dicenumber_defense = 5*(rand()%KDICE+1);
    
        hit_points = (enemy.features.attack + dicenumber_attack) - (hero.features.defense + dicenumber_defense); 
    
        if(hit_points<0){
            hit_points = 0;
        }
     
        hero.features.hp = hero.features.hp - hit_points;
      
        cout<< endl <<"Enemy -> Hero" << endl
        << "Attack: " << enemy.features.attack << " + " 
        << dicenumber_attack << endl
        << "Defense: " << hero.features.defense << " + "
        << dicenumber_defense << endl
        << "Hit points: " << hit_points << endl;
        
        if(hero.features.hp >=0){
            
            cout << "Hero health points: " << hero.features.hp << endl << endl;
        
        }else{
            
            cout << "Hero health points: 0" << endl << endl;
        }
    
        if(hero.features.hp > 0){
            
            showMenu(option, hero, enemy, runaway, special_attack);  
            
        }else{
            cout << "You are dead" << endl;
            report(hero);
        }
    }
}

void report(const Hero &hero){
    
    int i=0, j=0, total_killed=0;
    
    for(i; i<KENEMIES; i++){
        total_killed = total_killed + hero.kills[i];
    }
    
    cout << "[Report]"<< endl
    << "Name: " << hero.name << endl
    << "Attack: " << hero.features.attack << endl
    << "Defense: " << hero.features.defense << endl
    << "Health points: " << hero.features.hp << endl
    << "Special: ";
    
    if(hero.special){
        
        cout<< "yes" << endl;
        
    }else{
        
        cout<< "no" << endl;
    }
    
    cout << "Runaways: " << hero.runaways << endl
    << "Exp: " << hero.exp << endl
    << "Enemies killed:" << endl
    << "- Axolotl: " << hero.kills[0] << endl
    << "- Troll: " << hero.kills[1] << endl
    << "- Orc: " << hero.kills[2] << endl
    << "- Hellhound: " << hero.kills[3] << endl
    << "- Dragon: " << hero.kills[4] << endl
    << "- Total: " << total_killed << endl;
}


int main(int argc,char *argv[]){
  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
    cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios

    // Aquí vendrá todo tu código del "main"...
     
    char option;
    bool runaway=false, special_attack=false;
     
    Hero hero = createHero();
    Enemy enemy = createEnemy();

    showMenu(option, hero, enemy, runaway, special_attack);    
  }
}
