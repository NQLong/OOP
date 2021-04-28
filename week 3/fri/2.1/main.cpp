#include "book.h"

int main()
{
    Author *ahTeck = new Author("Tan Ah Teck", "ahteck@nowhere.com", 'm'); // Test the constructor
    cout << (ahTeck)->toString() << endl;                                  // Test toString()
    ahTeck->setEmail("paulTan@nowhere.com");                               // Test setter
    cout << ("name is: " + ahTeck->getName()) << endl;                     // Test getter
    cout << ("eamil is: " + ahTeck->getEmail()) << endl;                   // Test getter
    cout << ("gender is: " + ahTeck->getGender()) << endl;

    Book *dummyBook = new Book("Java for dummy", *ahTeck, 19.95, 99); // Test Book's Constructor
    cout << (dummyBook)->toString();                                  // Test Book's toString()
    
    // Test Getters and Setters
    dummyBook->setPrice(29.95);
    dummyBook->setQty(28);
    cout << ("name is: " + dummyBook->getName()) << endl;
    cout << "price is: " << dummyBook->getPrice() << endl;
    cout << ("qty is: " + dummyBook->getQty()) << endl;
    cout << "Author is: " << dummyBook->getAuthor().toString() << endl; // Author's toString()
    cout << ("Author's name is: " + dummyBook->getAuthor().getName()) << endl;
    cout << ("Author's email is: " + dummyBook->getAuthor().getEmail()) << endl;

    // Use an anonymous instance of Author to construct a Book instance
    Book* anotherBook = new Book("more Java",
                                *new Author("Paul Tan", "paul@somewhere.com", 'm'), 29.95);
    cout << (anotherBook)->toString(); // toString()
}