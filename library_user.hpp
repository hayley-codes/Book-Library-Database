#ifndef LIBRARY_USER_HPP
#define LIBRARY_USER_HPP
#include <string>
#include <vector>
using namespace std;

class LibraryUser {
private:
    string name;
    int user_id, borrowed_count;
public:
    LibraryUser();
    
    LibraryUser(string new_name, int new_id, int new_borrowed_count);

    virtual int get_borrow_limit() const = 0; // so that it can be overriden by child classes

    string get_name();

    int get_user_id();

    int get_borrowed_count();

    void borrow_book();

    void return_book();

    void print_user();
};

class Teacher : public LibraryUser {
private:
    int borrow_limit;
public:
    Teacher();

    Teacher(int borrow_limit, LibraryUser(string new_name, int new_id, int new_borrowed_count));

    int get_borrow_limit() const override;

    bool add_book_to_library(Library& library, Books* my_book);

    void print_teacher();
};

class Student : public LibraryUser {
private: 
    bool graduated;
    int borrow_limit;
public:
    Student();

    Student(bool graduated, int borrow_limit, LibraryUser(string new_name, int new_id, int new_borrowed_count));

    int get_borrow_limit() const override;

    void print_student();
};

#endif