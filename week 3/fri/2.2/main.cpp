#include "book.h"

int main()
{
    vector<Author> list;

    list.insert(list.end(), *new Author("Tan Ah Teck", "AhTeck@somewhere.com", 'm'));
    list.insert(list.end(), *new Author("Paul Tan", "Paul@nowhere.com", 'm'));

    // Declare and allocate a Book instance
    Book *javaDummy = new Book("Java for Dummy", list, 19.99, 99);
    cout << javaDummy->toString(); // toString()
}