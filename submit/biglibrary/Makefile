all: compiled/Account.o compiled/Patron.o compiled/Catalog.o  compiled/Library.o compiled/View.o compiled/Librarian.o compiled/User.o compiled/BookItem.o compiled/Book.o compiled/Author.o compiled/constraint.o compiled/main.o
	g++ compiled/*.o -o app



compiled/main.o: main.cpp
	g++ -c main.cpp -o compiled/main.o




compiled/View.o : Header/View/View.h Source/View/View.cpp
	g++ -c Source/View/View.cpp -o compiled/View.o



compiled/Catalog.o : Header/Catalog/Catalog.h Source/Catalog/Catalog.cpp
	g++ -c Source/Catalog/Catalog.cpp -o compiled/Catalog.o




compiled/Library.o : Header/Library/Library.h Source/Library/Library.cpp
	g++ -c Source/Library/Library.cpp -o compiled/Library.o




compiled/BookItem.o : Header/Book/BookItem.h Source/Book/BookItem.cpp
	g++ -c Source/Book/BookItem.cpp -o compiled/BookItem.o

compiled/Book.o : Header/Book/Book.h Source/Book/Book.cpp
	g++ -c Source/Book/Book.cpp -o compiled/Book.o



compiled/Account.o : Header/Actor/Account.h Source/Actor/Account.cpp
	g++ -c Source/Actor/Account.cpp -o compiled/Account.o

compiled/Patron.o : Header/Actor/Patron.h Source/Actor/Patron.cpp
	g++ -c Source/Actor/Patron.cpp -o compiled/Patron.o

compiled/Librarian.o : Header/Actor/Librarian.h Source/Actor/Librarian.cpp
	g++ -c Source/Actor/Librarian.cpp -o compiled/Librarian.o

compiled/User.o : Header/Actor/User.h Source/Actor/User.cpp
	g++ -c Source/Actor/User.cpp -o compiled/User.o



compiled/Author.o : Header/Author/Author.h Source/Author/Author.cpp
	g++ -c Source/Author/Author.cpp -o compiled/Author.o



compiled/constraint.o : Header/Constraint/constraint.h Source/Constraint/constraint.cpp
	g++ -c Source/Constraint/constraint.cpp -o compiled/constraint.o



clean:
	del compiled\*
	del  app
	cls

clear:
	rm -rf compiled/*.o
	rm app
	clear