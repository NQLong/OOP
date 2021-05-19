#include "Header/Constraint/Constraint.h"
#include "Header/Author/Author.h"
#include "Header/View/View.h"
#include "Header/Actor/User.h"
#include "Header/Actor/Librarian.h"
#include "Header/Actor/Patron.h"
#include "Header/Library/library.h"
#include "Header/Catalog/Catalog.h"

void init_data(Library *lib);

int main()
{
    Library library;
    init_data(&library);
    // library.get_cactalog()->brief_render({
    //     BookItem::get_book_item("1"),
    //     BookItem::get_book_item("2"),
    //     BookItem::get_book_item("3"),
    //     BookItem::get_book_item("4"),
    // });
    // wait();
    // BookItem::get_book_item("1")->modify_book_items();
    // library.get_cactalog()->add_book_view();
    View view;
    view.startApp(&library);
}

void init_data(Library *lib)
{
    Author::add_author(
        Author("Dracula", "every one borns and dies", time(0) - 20 * 365 * 3600 * 24));
    Author::add_author(
        Author("Arthor Conan Doyle", "my mind is a storage", time(0) - 20 * 365 * 3600 * 24));

    User::add_user(
        new Librarian(
            FullName("Jonh", "Walker"),
            Address("bleeker", "New York", "New York", "12312", "USA"),
            "admin",
            "1",
            "1"

            )

    );

    User::add_user(
        new Patron(
            FullName("Jonh4", "Walker"),
            Address("bleeker", "New York", "New York", "12312", "USA"),
            "2",
            "2"

            )

    );

    User::add_user(
        new Patron(
            FullName("Jonh3", "Walker"),
            Address("bleeker", "New York", "New York", "12312", "USA"),
            "3",
            "3"

            )

    );
    User::add_user(
        new Patron(
            FullName("Jonh2", "Walker"),
            Address("bleeker", "New York", "New York", "12312", "USA"),
            "4",
            "4"

            )

    );
    User::add_user(
        new Patron(
            FullName("Jonh1", "Walker"),
            Address("bleeker", "New York", "New York", "12312", "USA"),
            "5",
            "5"

            )

    );
    
    cout << *(Patron *)(User::get_users().back());
    wait();
    Catalog *cat = lib->get_cactalog();
    lib->add_book(
        cat->add_book(
            BookItem(
                "1123123", // ISBN
                {"Arthor Conan Doyle"}, "Sherlock homles",
                "Detective", "super detective", "UnKnown", time(0) - (long long)SECOND_IN_DAY * 365 * 20,
                ENGLISH,
                "1",       //barcode
                "1000000", //tag
                false, 654, HARDCOVER,
                time(0) - SECOND_IN_DAY * 15,
                10,
                time(0) - SECOND_IN_DAY * 5,
                0

                )

                )

    );
    lib->add_book(cat->add_book(
        BookItem(
            "234567", // ISBN
            {"Arthor Conan Doyle"}, "the adventures of tin tin",
            "Detective", "super detective", "UnKnown", time(0) - (long long)SECOND_IN_DAY * 365 * 30,
            ENGLISH,
            "2",        //barcode
            "12345678", //tag
            false, 654, PDF, -1, 14, -1, 0

            ))

    );
    lib->add_book(cat->add_book(
        BookItem(
            "123456", // ISBN
            {"Arthor Conan Doyle"}, "Harry Potter",
            "Detective", "wizards' world", "UnKnown", time(0) - (long long)SECOND_IN_DAY * 365 * 30,
            ENGLISH,
            "3",        //barcode
            "22334455", //tag
            false, 654, HARDCOVER, -1, 14, -1, 0

            ))

    );
lib->add_book(
    cat->add_book(
        BookItem(
            "123456", // ISBN
            {"Arthor Conan Doyle"}, "Harry Potter",
            "Detective", "wizards' world part2", "UnKnown", time(0) - (long long)SECOND_IN_DAY * 365 * 30,
            ENGLISH,
            "4",        //barcode
            "22334455", //tag
            false, 654, PAPERBACK, -1, 14, -1, 0

            )
    )
    );
}
