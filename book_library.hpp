#ifndef BOOK_LIBRARY_HPP
#define BOOK_LIBRARY_HPP
#include <string>
#include <vector>
using namespace std;

class Books {
private:
    string book_title, author, d_o_p, genre;

public:
    Books();

    Books(string new_title, string new_author, string new_dop, string genre);

    Books(string new_title, string new_author, string new_dop);

    Books(string new_title, string new_author);

    Books(string new_title);

    bool operator==(const Books& other) const;

    void print();

    string get_book_title();

    string get_author();

    string get_dop();

    string get_genre();


};

class Library {
private:
    vector<Books*> books; // The attribute itself is still a vector of objects, the constuctor will paramatize pointers of the vector.
    vector<bool> is_borrowed;

public:
    Library();

    Library(vector<Books*> new_books, vector<bool> new_borrowed);

    void print();

    bool insert(Books* my_book);

    bool remove(Books* my_book);

    void advanced_search(Books searching_book);

    // NEW ADDITIONS --> add this when combining with Hayley
    bool borrow_book(LibraryUser& user, const string& title);

    bool return_book(LibraryUser& user, const string& title);

    vector<Books*> get_books();

};

#endif