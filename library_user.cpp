#include <iostream>
#include <vector>
#include <string>
#include "library_user.hpp"
#include "book_library.hpp"
using namespace std;

//LIBRARY_USER CONTRUCTORS 

LibraryUser::LibraryUser(){}

LibraryUser::LibraryUser(string new_name, int new_id, int new_borrowed_count){
    new_name = name;
    new_id = user_id;
    new_borrowed_count = borrowed_count;
}


//LIBRARY_USER METHODS 


string LibraryUser::get_name(){
    return name;
}

int LibraryUser::get_user_id(){
    return user_id;
}

int LibraryUser::get_borrowed_count(){
    return borrowed_count;
}

void LibraryUser::borrow_book(){
    borrowed_count++;
}

void LibraryUser::return_book(){
    borrowed_count--;
}

void LibraryUser::print_user(){
    cout << "Name: " << name << " User ID: " << user_id << " Number of Borrowed Books: " << borrowed_count << endl;
}

// TEACHER CONSTRUCTORS

Teacher::Teacher(){}
Teacher::Teacher(int new_borrow_limit, LibraryUser(string new_name, int new_id, int new_borrowed_count)){
}

// TEACHER METHODS
    
int Teacher::get_borrow_limit() const{
    return borrow_limit;
}

bool Teacher::add_book_to_library(Library& library, Books* my_book){
    for (int i=0; i < library.get_books().size(); i++){
        if (*library.get_books()[i] == *my_book){
            cout << "Book already in library." << endl;
            return false;
        }
    }
    library.insert(my_book);
    return true;
}

void Teacher::print_teacher(){
    cout << "User Type: Teacher  Borrow Limit: " << borrow_limit << " ";
    print_user();
}

// STUDENT CONSTRUCTOR
Student::Student(){}

Student::Student(bool graduated, int borrow_limit, LibraryUser(string new_name, int new_id, int new_borrowed_count)){}

int Student::get_borrow_limit() const{
    return borrow_limit;
}

void Student::print_student(){
     cout << "User Type: Student  Borrow Limit: " << borrow_limit << "Graduated: " << graduated << " ";
    print_user();
}