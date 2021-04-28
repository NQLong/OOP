#include "book.h"

int main()
{
    Author a1 = Author("Tan Ah Teck", "ahteck@nowhere.com", "m");
    cout << a1 << endl;

    a1.setEmail("ahteck@somewhere.com");
    cout << (a1) << endl;
    cout << ("name is: " + a1.getName());
    cout << ("email is: " + a1.getEmail());

    // Test Book class
    Book b1 = Book("12345", "Java for dummies", a1, 8.8, 88);
    cout << (b1);
    cout << endl;

    b1.setPrice(9.9);
    b1.setQty(99);
    cout << (b1);
    cout << ("isbn is: " + b1.getName());
    cout << endl;
    cout << ("name is: " + b1.getName());
    cout << endl;
    cout << "price is: " << b1.getPrice();
    cout << endl;
    cout << "qty is: " << b1.getQty();
    cout << endl;
    cout << "author is: " << b1.getAuthor(); // Author's toString()
    cout << endl;
    cout << "author's name: " << b1.getAuthorName();
    cout << endl;
    cout << ("author's name: " + b1.getAuthor().getName());
    cout << endl;
    cout << ("author's email: " + b1.getAuthor().getEmail());
    cout << endl;
}