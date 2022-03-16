/* Programación 2 - Práctica 1
 * DNI:48776731X
 * NOMBRE: Esther Peral Soler
 * Token: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
 */

#include <iostream>
#include <vector>
#include <cctype>


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
void importFromCsv(BookStore &bookStore);
void exportToCsv(const BookStore &bookStore);
void loadData(BookStore &bookStore);
void saveData(const BookStore &bookStore);

void bookTitle(Book book);
void bookAuthor(Book book);
void bookDate(Book book);
void bookPrice(Book book);



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

    
}

void showExtendedCatalog(const BookStore &bookStore) {

    
}

void bookTitle(Book book){
    
    bool valid=true; //si es true lo introducido es válido y si es false no
    
    cout<<"Enter book title: "<<endl;
    getline(cin, book.title);
    
    int lon = book.title.size(); //mide la longitud de la cadena introducida
    //comprobar nombre
    
    for(int i=0; i<lon; i++){
        if(not((isalnum(book.title[i])) || book.title[i]==' ' || book.title[i]==':' || book.title[i]==',' || book.title[i]=='-')){
            i = lon;
            valid = false;
            cout<<"No valido1"<<endl;
            error(ERR_BOOK_TITLE);
        }
    }
    
   while(!valid){
        cout<<"Enter book title: "<<endl;
        getline(cin, book.title);
    
        lon = book.title.size();
        
        valid = true;
        
        for(int i=0; i<lon; i++){
            if(not((isalnum(book.title[i])) || book.title[i]==' ' || book.title[i]==':' || book.title[i]==',' || book.title[i]=='-')){
                i = lon;
                valid = false;
                cout<<"No valido2"<<endl;
                error(ERR_BOOK_TITLE);
            }
        }
    }
    
    for(int i=0; i<lon; i++){
        if(isalpha(book.title[i])){
           book.title[i]=tolower(book.title[i]);
        }else if(book.title[i]==' ' || book.title[i]==':' || book.title[i]==','){
            book.title[i]='-';
        }
        book.slug[i] = book.title[i];
    }
    
    for(int i=0; i<lon; i++){
        if(book.slug[i]=='-' && book.slug[i+1]=='-'){
            for(int j=i; j<lon; j++){
                book.slug[j]=book.slug[j+1];
            }
        }
        cout<<book.slug[i];
    }
    
   
}

void bookAuthor(Book book){
    
    bool valid=true; //si es true lo introducido es válido y si es false no
    
    cout<<"Enter author(s): "<<endl;
    getline(cin, book.authors);
    //comprobar titulo
    
     int lon = book.authors.size(); //mide la longitud de la cadena introducida
    //comprobar nombre
    
    for(int i=0; i<lon; i++){
        if(not((isalnum(book.authors[i])) || book.authors[i]==' ' || book.authors[i]==':' || book.authors[i]==',' || book.authors[i]=='-')){
            i = lon;
            valid = false;
            cout<<"No valido1"<<endl;
            error(ERR_BOOK_AUTHORS);
        }
    }
    
   while(!valid){
        cout<<"Enter author(s): "<<endl;
        getline(cin, book.authors);
    
        lon = book.authors.size();
        
        valid = true;
        
        for(int i=0; i<lon; i++){
            if(not((isalnum(book.authors[i])) || book.authors[i]==' ' || book.authors[i]==':' || book.authors[i]==',' || book.authors[i]=='-')){
                i = lon;
                valid = false;
                cout<<"No valido2"<<endl;
                error(ERR_BOOK_AUTHORS);
            }
        }
    }
}

void bookYear(Book book){

    bool valid = true;
    
    cout<<"Enter publication year: "<<endl;
    cin>>book.year;
    //comprobar año
   
    
   if(book.year<1440 || book.year>2022){
            valid = false;
    }else{
        valid = true;
    }
   
    while(!valid){
            error(ERR_BOOK_DATE);
            
            cout<<"Enter publication year: "<<endl;
            cin>>book.year;
    
            if(book.year<1440 || book.year>2022){
                valid = false;
            }else{
                valid = true;
            } 
    }   
}

void bookPrice(Book book){

    bool valid= true;
    cout<<"Enter price: "<<endl;
    cin>>book.price;
    //comprobar precio
    
    if(book.price<=0){
        valid = false;
    }else{
        valid = true;
    }
   
    while(!valid){
        error(ERR_BOOK_PRICE);
            
        cout<<"Enter price: "<<endl;
        cin>>book.price;
    
        if(book.price<=0){
            valid = false;
        }else{
            valid = true;
        } 
    }
}

void addBook(BookStore &bookStore){
    
    Book book;
    
    bookTitle(book); //comprobamos título
    bookAuthor(book); //comprobamos autor  
    bookYear(book); //comprobamos año
    bookPrice(book); //comprobamos precio
    
    book.id = bookStore.nextId; 
    bookStore.nextId++;

    bookStore.books.push_back(book);
}

void deleteBook(BookStore &bookStore) {
    
    cout<<"Enter book id: "<<endl;
    
}

void importExportMenu(BookStore &bookStore) {
}

void importFromCsv(BookStore &bookStore){
}

void exportToCsv(const BookStore &bookStore){
}

void loadData(BookStore &bookStore){
}

void saveData(const BookStore &bookStore){
}

int main(int argc, char *argv[]) {
  BookStore bookStore;
  bookStore.name = "My Book Store";
  bookStore.nextId = 1;

  //Error e; //declaramos variable para el error
  char option;
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

  return 0;
}
