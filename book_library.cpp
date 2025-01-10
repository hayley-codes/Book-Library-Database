#include <iostream>
#include <vector>
#include <string>
#include "book_library.hpp"
#include "library_user.hpp"
using namespace std;

// BOOKS CONSTRUCTORS
Books::Books(): // Constructor with no parameters
    book_title("N/A"), author("N/A"), d_o_p("N/A"){}

Books::Books(string new_title, string new_author, string new_dop, string new_genre): // Constructor with 4 parameters
    book_title(new_title), author(new_author), d_o_p(new_dop), genre(new_genre){}

Books::Books(string new_title, string new_author, string new_dop): // Constructor with 3 parameters
    book_title(new_title), author(new_author), d_o_p(new_dop){}

Books::Books(string new_title, string new_author): // Constructor with title and author parameters
    book_title(new_title), author(new_author), d_o_p("N/A"){}

Books::Books(string new_title):// Constructor with title parameter
    book_title(new_title), author("N/A"), d_o_p("N/A"){}

// LIBRARY CONTRUCTORS
Library::Library(){} // Library constructor with no parameters

Library::Library(vector<Books*> new_books, vector<bool> new_borrowed) { // Library constructor takes book vector of pointers and appends the pointers, one-by-one, to a library vector 
    for (int i=0; i < new_books.size(); i++){ //iterating through the vector of pointers for the new books to be added
        books.push_back(new_books[i]);
        is_borrowed.push_back(false);
    } 
}

// BOOKS METHODS
void Books::print(){
    cout << "Title: " << book_title << endl; 
    cout << "Author: " << author << endl; 
    cout << "Date of Publication: " << d_o_p << endl; 
    cout << "Genre: " << genre << endl;
}

bool Books::operator==(const Books& other) const{ // Checking the equality of complex attributes using an overloaded operator.
    return book_title == other.book_title && author == other.author && d_o_p == other.d_o_p && genre == other.genre;
}

string Books::get_book_title(){ // The get function allows access to private attributes by returning them publically
    return book_title;
}

string Books::get_author(){
    return author;
}

string Books::get_dop(){
    return d_o_p;
}

string Books::get_genre(){
    return genre;
}

// LIBRARY METHODS

void Library::print(){
    if (books.empty()){
        cout << "Library is empty." << endl;
    }
    else
        for(int i=0; i < books.size(); i++){
            cout << "Index: " << i << endl;
            books[i]->print(); // the -> arrow operator is a shorthand for dereferencing a pointer and accessing a member of this object
        }
        cout << " " << endl;
}

void Library::advanced_search(Books searching_book){
    for (int i=0; i < books.size(); i++){
        size_t position_match_title = books[i]->get_book_title().find(searching_book.get_book_title());
        size_t position_match_author = books[i]->get_author().find(searching_book.get_author());
        size_t position_match_dop = books[i]->get_dop().find(searching_book.get_dop());
        size_t position_match_genre = books[i]->get_genre().find(searching_book.get_genre());
        
        if (position_match_title != string::npos || 
        position_match_author != string::npos || 
        position_match_dop != string::npos || 
        position_match_genre != string::npos){ //size_t is a c++ data type which is good to use for the find function, as it only returns naturel numbers, including zero.
            
            cout << "Is this what you where looking for?" << endl;
            books[i]->print();
        }
    }
}

bool Library::remove(Books* my_book){
    for (int i=0; i < books.size(); i++){
        if (*books[i] == *my_book){
            books.erase(books.begin() + i);
            cout << "Book has been removed." << endl;
            is_borrowed[i]==false;
            return true;
        }
    }
    cout<< "Book has not been found to remove." << endl;
    return false;
}

bool Library::insert(Books* my_book){
    for (int i=0; i < books.size(); i++){
        if (*books[i] == *my_book){
            cout << "Book already in library." << endl;
            return false;
        }
    }
    books.push_back(my_book);
    is_borrowed.push_back(true);
    return true;
}

// NEW ADDITIONS --> add this when combining with Hayley
bool Library::borrow_book(LibraryUser& user, const string& title ){
    
    for (int i = 0; i < books.size(); i++){
        if((books[i]->get_book_title() == title) && (is_borrowed[i] == false) && (user.get_borrowed_count() <= user.get_borrow_limit() )){
            user.borrow_book();
            cout << user.get_name() << " borrowed " << title << endl;
            return is_borrowed[i] = true;
        }
        else if (user.get_borrowed_count() == user.get_borrow_limit() ){
            cout << "User is has reached borrow limit and cannot borrow a book" << endl;
            return is_borrowed[i] = false;
        }
        else if ((books[i]->get_book_title() == title) &&(is_borrowed[i] == true)){
            cout << "This book is already borrowed, please wait for it to be returned" <<  endl;
            return is_borrowed[i] = false;
        }
    }

    cout << "This book doesn't exist" << endl;
    return false;
}

bool Library::return_book(LibraryUser& user,const string& title){

    for (int i = 0; i < books.size(); i++){
        if((books[i]->get_book_title() == title) && (is_borrowed[i] == true)){
            user.return_book();
            cout << user.get_name() << "returned" << title << endl;
            return is_borrowed[i] = false;
        }
        else if ((books[i]->get_book_title() == title) && (is_borrowed[i] == false)){
            cout << title << " has not been borrowed yet, it cannot be returned." << endl;
            return is_borrowed[i] = false;
        }
    }

    cout << "This book doesn't exist" << endl;
    return true;   

}

vector<Books*> Library::get_books(){
    return books;
}