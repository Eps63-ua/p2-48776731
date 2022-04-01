/* Programación 2 - Práctica 2
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

const int KMAXSTRING = 50;

enum Error {
  ERR_OPTION,
  ERR_BOOK_TITLE,
  ERR_BOOK_AUTHORS,
  ERR_BOOK_DATE,
  ERR_BOOK_PRICE,
  ERR_ID,
  ERR_FILE,
  ERR_ARGS
};

struct Book {
  unsigned int id;
  string title;
  string authors;
  int year;
  string slug;
  float price;
};

struct BinBook {
  unsigned int id;
  char title[KMAXSTRING];
  char authors[KMAXSTRING];
  int year;
  char slug[KMAXSTRING];
  float price;
};

struct BookStore {
  string name;
  vector<Book> books;
  unsigned int nextId;
};

struct BinBookStore {
  char name[KMAXSTRING];
  unsigned int nextId;
};

void error(Error e);
void showMainMenu();
void showCatalog(const BookStore &bookStore);
void showExtendedCatalog(const BookStore &bookStore);
void addBook(BookStore &bookStore);
void deleteBook(BookStore &bookStore);
void importExportMenu(BookStore &bookStore);
void importFromCsv(BookStore &bookStore, string filename);
void exportToCsv(const BookStore &bookStore);
void loadData(BookStore &bookStore, string filename);
void saveData(const BookStore &bookStore);

int argumentos(int argc, char *argv[], BookStore &bookStore);

void bookTitle(Book &book);
void bookAuthor(Book &book);
void bookYear(Book &book);
void bookPrice(Book &book);
void bookSlug(Book &book);

void askLoad(BookStore &bookStore);
void askImport(BookStore &bookStore);

bool checkString(string s, Error e);
void detCadena(char cadena[KMAXSTRING], int &i, const string &l);


void error(Error e) {
  switch (e) {
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_BOOK_TITLE:
      cout << "ERROR: wrong book title" << endl;
      break;
    case ERR_BOOK_AUTHORS:
      cout << "ERROR: wrong author(s)" << endl;
      break;
    case ERR_BOOK_DATE:
      cout << "ERROR: wrong date" << endl;
      break;
    case ERR_BOOK_PRICE:
      cout << "ERROR: wrong price" << endl;
      break;
    case ERR_ID:
      cout << "ERROR: wrong book id" << endl;
      break;
    case ERR_FILE:
      cout << "ERROR: cannot open file" << endl;
      break;
    case ERR_ARGS:
      cout << "ERROR: wrong arguments" << endl;
      break;
  }
}

void showMainMenu() {
  cout << "[Options]" << endl
       << "1- Show catalog" << endl
       << "2- Show extended catalog" << endl
       << "3- Add book" << endl
       << "4- Delete book" << endl
       << "5- Import/export" << endl
       << "q- Quit" << endl
       << "Option: ";
}

void showCatalog(const BookStore &bookStore) {
    
    int numbooks = bookStore.books.size(); //número de libros
    int lon; //medirá la longitud de la cadena que necesitemos en ese momento
    
    for(int i=0; i<numbooks; i++){
        cout << bookStore.books[i].id << ". " ;
        lon= bookStore.books[i].title.size();
        
        for(int j=0; j<lon; j++){
            cout<<bookStore.books[i].title[j];
        }
        cout <<" (" << bookStore.books[i].year 
        << "), " << bookStore.books[i].price << endl;
    }
}

void showExtendedCatalog(const BookStore &bookStore) {

    int numbooks = bookStore.books.size(); //número de libros
    int lon; //medirá la longitud de la cadena que necesitemos en ese momento
    int i=0, j=0; //contadores for
    
    for(i=0; i<numbooks; i++){
        cout << '"';
        lon= bookStore.books[i].title.size();
        
        for(j=0; j<lon; j++){
            cout<<bookStore.books[i].title[j];
        }
        cout << '"'<<","<<'"';
        lon= bookStore.books[i].authors.size();
        
        for(j=0; j<lon; j++){
            cout<<bookStore.books[i].authors[j];
        }
        cout << '"'<<","<< bookStore.books[i].year << ","<<'"';
        lon= bookStore.books[i].slug.size();
        
        for(j=0; j<lon; j++){
            cout<<bookStore.books[i].slug[j];
        }
        cout<< '"'<<"," << bookStore.books[i].price << endl;
    }
}

bool checkString(string s, Error e){
    
    bool valid=false; 
    int lon = s.size(); //mide la longitud de la cadena introducida

    if(lon==0){ //comprobamos que la cadena no esté vacia
        valid = false;
        error(e);
    }
        
        for(int i=0; i<lon; i++){
        if(not((isalnum(s[i])) || s[i]==' ' || s[i]==':' || s[i]==',' || s[i]=='-')){
            i = lon;
            valid = false;
            error(e);
        }else if(s.empty()){
            i = lon;
            valid = false;
            error(e);
        }else{
            valid=true;
   
        }
    }
    return valid;
}

void bookTitle(Book &book){
    
    bool valid=false; //si es true lo introducido es válido y si es false no
    stringstream blsdjh;
    
    while(!valid){
        cout<<"Enter book title: ";
        getline(cin, book.title);
        
        valid=checkString(book.title, ERR_BOOK_TITLE);
       
        bookSlug(book); //creamos el slug del libro
    }
}

void bookSlug(Book &book){
 
    book.slug = book.title; //empezamos poniendo en el slug el título y sobre este vamos haciendo los cambios
    int i=0;
    
    if(book.slug[0]=='-'){
        book.slug.erase(0,1);
    }
    
    int lon = book.slug.size();
        
    for(i=0; i<lon; i++){
        if(isalpha(book.slug[i])){
           book.slug[i]=tolower(book.slug[i]); //pasar mayusculas a minusculas
        }else if(book.slug[i]==' ' || book.slug[i]==':' || book.slug[i]==','){
            book.slug[i]='-'; //cambiamos lo que no sea una letra por -
        }
    }
    
    for(i=0; i<lon; i++){
        if(book.slug[i]=='-' && book.slug[i+1]=='-'){ //comprobamos si hay 2 -- seguidos
            book.slug.erase(i,1); //borramos en la posicion i 1 elemento
            lon = book.slug.size();
        }
        for(int j=i; j<lon; j++){
            if(book.slug[j]=='-' && book.slug[j+1]=='-'){ //comprobamos si hay mas de 2 -- seguidos
                book.slug.erase(j,1); 
                lon = book.slug.size();
            }
        }
    }

    if(book.slug[lon-1]=='-'){ //comprobamos que el ultimo char no sea -
        book.slug.erase(lon-1,1);
    }
}

void bookAuthor(Book &book){
    
    bool valid=false; //si es true lo introducido es válido y si es false no
    
    while(!valid){
        cout<<"Enter author(s): ";
        getline(cin, book.authors);
        
        valid=checkString(book.authors, ERR_BOOK_AUTHORS);
    }
}

void bookYear(Book &book){

    bool valid = false;
    string stryear;
   
    while(!valid){
            
        cout<<"Enter publication year: ";
        getline(cin, stryear);
            
        int lon = stryear.size(); //mide la longitud de la cadena introducida
    
        if(lon==0){ //comprobamos que la cadena no esté vacia
            valid = false;
            error(ERR_BOOK_DATE);
        }else{
         
            book.year=stoi(stryear);
            
            if(book.year<1440 || book.year>2022){
                valid = false;
                error(ERR_BOOK_DATE);
            }else{
                valid = true;
            } 
        }
    }   
}

void bookPrice(Book &book){

    bool valid= false;
    string strprice;
   
    while(!valid){
            
        cout<<"Enter price: ";
        getline(cin, strprice);
            
        int lon = strprice.size(); //mide la longitud de la cadena introducida
    
        if(lon==0){ //comprobamos que la cadena no esté vacia
            valid = false;
            error(ERR_BOOK_PRICE);
        }else{
         
            book.price=stof(strprice);
        
            if(book.price<=0){
                valid = false;
                error(ERR_BOOK_PRICE);
            }else{
                valid = true;
            } 
        }
    }
}

void addBook(BookStore &bookStore){
    
    Book newbook;
    
    bookTitle(newbook); //comprobamos título
    bookAuthor(newbook); //comprobamos autor  
    bookYear(newbook); //comprobamos año
    bookPrice(newbook); //comprobamos precio
    
    newbook.id = bookStore.nextId; 
    bookStore.nextId++;

    bookStore.books.push_back(newbook);
}

void deleteBook(BookStore &bookStore){
    
    unsigned int idbooks=bookStore.nextId; //indica el ultimo id utilizado
    unsigned int deleteId; 
    bool valid=false; //indica si el id es valido
    unsigned int i=0; 
    unsigned int numbooks=bookStore.books.size(); //indica el número de libros que hay
    
    cout<<"Enter book id: "<<endl;
    cin>>deleteId;
    
    if(deleteId>idbooks){
        error(ERR_ID);
    }else{
    
        for(i=0; i<=numbooks && !valid; i++){
            if(deleteId!=bookStore.books[i].id){
                valid=false;
            }else{
                valid=true;
            }
        }
        if(!valid){
            error(ERR_ID);
        }else{
            bookStore.books.erase(bookStore.books.begin()+(i-1));
        }
    }
}

void importExportMenu(BookStore &bookStore) {
    
    char option; 
    
    cout << "[Import/export options]" << endl
       << "1- Import from CSV" << endl
       << "2- Export to CSV" << endl
       << "3- Load data" << endl
       << "4- Save data" << endl
       << "b- Back to main menu" << endl
       << "Option: ";
    
    cin >> option;
    cin.get();
    
    switch(option){
        case '1':
            askImport(bookStore);                    importExportMenu(bookStore);
            break;
        case '2':
            exportToCsv(bookStore);
            importExportMenu(bookStore); 
            break;
        case '3':
            askLoad(bookStore);
            importExportMenu(bookStore);
            break;
        case '4':
            saveData(bookStore);
            importExportMenu(bookStore);
            break;
        case 'b':
            break;
        default:
            error(ERR_OPTION);
    }
}

void detCadena(char cadena[KMAXSTRING], int &i, const string &l){
    
    int j=0;   //este módulo nos permite separar dentro del string por \ las partes que nos interesan dejando una estructura de nombre\autor\año\slug\precio

    while(l[i]!='\"'){
        cadena[j]=l[i];
        i++;    
        j++;
    }
    i=i+3;
    cadena[j]='\0';
}

void askImport(BookStore &bookStore){
    
    string filename;
    
    cout<<"Enter file name: ";
    getline(cin, filename);
    
    importFromCsv(bookStore, filename);

}

void importFromCsv(BookStore &bookStore, string filename){
    
    string l;
    ifstream ficheroLeer;
    ficheroLeer.open(filename);
   
    if(ficheroLeer.is_open()){
        while(getline(ficheroLeer, l)){
            int i=1, byear=0;  // i será el contador de los carácteres en el string de cada linea y declaramos las partes de un book(b) para luego igualarlos (b-variable)
            float bprice=0;
            char bslug[KMAXSTRING];
            char btitle[KMAXSTRING];
            char bauthor[KMAXSTRING];
            
            
            bool check =true;   //indica que cada apartado es correcto
            
            detCadena(btitle, i, l);//determinamos hasta donde llega el titulo
            check=checkString(btitle, ERR_BOOK_TITLE); //comprobamos titulo
            
            if(check){
                detCadena(bauthor, i, l); //determinamos hasta donde llega el autor
                check=checkString(bauthor, ERR_BOOK_AUTHORS); //comprobamos cadena
            }
            
            if(check){
                while(l[i-1]!=','){
                    byear=byear*10+(l[i-1]-'0');
                    i++;
                }
                
                if(byear<1440 || byear>2022){
                    check = false;
                    error(ERR_BOOK_DATE);
                }else{
                    check = true;
                }
                i++;
            }
            
            if(check){
                detCadena(bslug, i, l);
            }
            
            if(check){
                i--;
                int z=0;
                while(l[i]!='\0'){
                    if(l[i]=='.'){
                        z++;
                    }else if(l[i-z]=='.'){
                        bprice=bprice+((l[i]-'0')*pow(10, -z));
                        z++;
                    }else{
                        bprice=bprice*10+(l[i]-'0');
                    }
                    i++;
                }
            
                if(bprice<=0){
                    check = false;
                    error(ERR_BOOK_PRICE);
                }else{
                    check = true;
                }
            }
            
            if(check){
                Book book; 
                book.title=btitle;
                book.authors=bauthor;
                book.year=byear;
                book.slug=bslug;
                book.price=bprice;
                book.id=bookStore.nextId;
                bookStore.nextId++;
                bookStore.books.push_back(book);
            }
        }
        
        ficheroLeer.close();
    }else{
        error(ERR_FILE);
    }
}

void exportToCsv(const BookStore &bookStore){
    
    string filename;
    unsigned int lon = bookStore.books.size();
    
    cout<<"Enter filename: ";
    getline(cin, filename);
   
  
    ofstream ficheroEsc;
    ficheroEsc.open(filename, ios::out);
   
    if(ficheroEsc.is_open()){
        for(unsigned int i=0; i<lon; i++){
            ficheroEsc << '"' << bookStore.books[i].title 
            << '"'<<","<<'"'<< bookStore.books[i].authors
            << '"'<<","<< bookStore.books[i].year 
            << ","<<'"'<<bookStore.books[i].slug
            << '"'<<"," << bookStore.books[i].price << endl;
        }
            
        ficheroEsc.close();
    }else{
        error(ERR_FILE);
    }
}

void askLoad(BookStore &bookStore){

    char answer;
    string filename;
    int lon=bookStore.books.size();
    
    cout<<"All data will be erased, do you want to continue (Y/N)?: ";
    cin>>answer;
    cin.get();
    
    if(answer=='y' || answer=='Y'){
        
        for(int i=0; i<lon; i++){
             bookStore.books.erase(bookStore.books.begin()+(1));
        }
        cout<<"Enter file name: ";
        getline(cin, filename);
        
        loadData(bookStore, filename);
    }else if(answer=='n' || answer=='N'){
        importExportMenu(bookStore);
    }else{
        askLoad(bookStore);
    }
}

void loadData(BookStore &bookStore, string filename){
    
    BinBook bBook;
    BinBookStore bBookStore;
    Book book;
    
    ifstream ficheroLoad;
    ficheroLoad.open(filename, ios::binary);
    
    if(ficheroLoad.is_open()){
        while(ficheroLoad.read((char*)&bBookStore, sizeof(BinBookStore))){
            bookStore.name=bBookStore.name;
            bookStore.nextId=bBookStore.nextId;
            
            while(ficheroLoad.read((char*)&bBook, sizeof(BinBook))){
                book.id=bBook.id;
                book.title=bBook.title;
                book.slug=bBook.slug;
                book.authors=bBook.authors;
                book.year=bBook.year;
                book.price=bBook.price;
                    
                bookStore.books.push_back(book);
            }
        }
        ficheroLoad.close();
    }else{
        error(ERR_FILE);
    }
}

void saveData(const BookStore &bookStore){
    
    string filename;
    
    int lon=bookStore.books.size();
    
    BinBook bBook;
    BinBookStore bBookStore;
    
    
    cout<<"Enter filename: ";
    getline(cin, filename);
    
    ofstream ficheroSave;
    ficheroSave.open(filename, ios::out | ios::binary);
    
    if(ficheroSave.is_open()){
        //empezamos a copiar la información teniendo en cuenta que hay q copiar solamente 49 dígitos de las cadenas y en la última posición añadimos un espacio
        strncpy(bBookStore.name, bookStore.name.c_str(), (KMAXSTRING-1)); //copiamos nombre y el valor de nextId del bookStore
        bBookStore.name[KMAXSTRING-1]='\0';
        bBookStore.nextId=bookStore.nextId;
        
        ficheroSave.write((const char*)&bBookStore, sizeof(BinBookStore));
        
        for(int i=0; i<lon; i++){
            bBook.id=bookStore.books[i].id;  //copiamos todas las cadenas, con las restricciones de antes, pertenecientes a la estructura book
            bBook.year=bookStore.books[i].year;
            bBook.price=bookStore.books[i].price;
            
            strncpy(bBook.title, bookStore.books[i].title.c_str(), KMAXSTRING-1); 
            bBook.title[KMAXSTRING-1]='\0';
            
            strncpy(bBook.slug, bookStore.books[i].slug.c_str(), KMAXSTRING-1); 
            bBook.slug[KMAXSTRING-1]='\0';
            
            strncpy(bBook.authors, bookStore.books[i].authors.c_str(), KMAXSTRING-1); 
            bBook.authors[KMAXSTRING-1]='\0';            
             
             ficheroSave.write((const char*)&bBook, sizeof(BinBook));
        }
        ficheroSave.close();
    }else{
        error(ERR_FILE);
    }
}

int argumentos(int argc, char *argv[], BookStore &bookStore){
    
    //argc=número de argunemtos, argv[x] nos permite saber el argumento que ocupa la posción x

    int valid_arg;
    
     
    if(argc==1){
        valid_arg=1;
    }else{
        if(argc<=5 && argc%2==1){ //comprobamos que tenga menos de 6 argumentos y que sean un número impar
            valid_arg=1;
        
            if(strcmp(argv[1], "-l")!=0 && strcmp(argv[1], "-i")!=0){ //comprobamos que el primer argumento sea -l o -i
                valid_arg=0;
            }else{
        
                if(argc==3){
                    ifstream fichero1(argv[2]);
                    if(fichero1.is_open()){
                        valid_arg=1;
                        fichero1.close();
                    }else{
                        valid_arg=2;
                    }
                    
                    if(valid_arg==1 && strcmp(argv[1], "-l")==0){
                        loadData(bookStore, argv[2]);
                    }else if(valid_arg==1){
                        importFromCsv(bookStore, argv[2]);
                    }
                }
            
                if(valid_arg==1 && argc==5){
                    if((strcmp(argv[3], "-l")!=0 && strcmp(argv[3], "-i")!=0) || (strcmp(argv[1], argv[3])==00)){ //comprobamos que el segundo argumento sea -i o -l y que los dos no sean iguales
                        valid_arg=0;
                    }else{
                        
                        ifstream fichero1(argv[2]);
                        ifstream fichero2(argv[4]);
                        if(fichero1.is_open() && fichero2.is_open()){
                            valid_arg=1;
                            fichero1.close();
                            fichero2.close();
                        }else{
                            valid_arg=2;
                            error(ERR_FILE);
                        }
                        
                        if(valid_arg==1 && strcmp(argv[1], "-l")==0){//si tenemos los dos argumentos hacemos load primero
                            loadData(bookStore, argv[2]);
                            importFromCsv(bookStore, argv[4]);
                            
                        }else if(valid_arg==1){
                            loadData(bookStore, argv[4]);
                            importFromCsv(bookStore, argv[2]);
                        }
                    }   
                }  
            }
        }else{
            valid_arg=0;
        }
    }
    return(valid_arg);
}

int main(int argc, char *argv[]) {
  BookStore bookStore;
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;

  int arg = argumentos(argc, argv, bookStore);
  char option;
  
  if(arg==1){
    do {
        showMainMenu();
        cin >> option;
        cin.get();

        switch (option) {
        case '1':
            showCatalog(bookStore);
            break;
        case '2':
            showExtendedCatalog(bookStore);
            break;
        case '3':
            addBook(bookStore);
            break;
        case '4':
            deleteBook(bookStore);
            break;
        case '5':
            importExportMenu(bookStore);
            break;
        case 'q':
            break;
        default:
            error(ERR_OPTION);
        }
    } while (option != 'q');
  
  }else if(arg==0){
      error(ERR_ARGS);
  }else{
      error(ERR_FILE);
  }
  return 0;
}
