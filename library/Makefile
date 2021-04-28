

compiled/main.o: main.cpp
	g++ -c main.cpp -o compiled/main.o 
#############################View
compiled/View.o: view/Source/View.cpp view/Header/View.h
	g++ -c view/Source/View.cpp -o compiled/View.o 

compiled/LibrarianView.o: view/Source/LibrarianView.cpp view/Header/LibrarianView.h
	g++ -c view/Source/LibrarianView.cpp -o compiled/LibrarianView.o

compiled/MemberView.o: view/Source/MemberView.cpp view/Header/MemberView.h
	g++ -c view/Source/MemberView.cpp -o compiled/MemberView.o

compiled/MainView.o: view/Source/MainView.cpp view/Header/MainView.h
	g++ -c view/Source/MainView.cpp -o compiled/MainView.o

####################Controller
compiled/BaseController.o: controller/Source/BaseController.cpp controller/Header/BaseController.h
	g++ -c controller/Source/BaseController.cpp -o compiled/BaseController.o

compiled/AuthorController.o: controller/Source/AuthorController.cpp controller/Header/AuthorController.h
	g++ -c controller/Source/AuthorController.cpp -o compiled/AuthorController.o

compiled/UserController.o: controller/Source/UserController.cpp controller/Header/UserController.h
	g++ -c controller/Source/UserController.cpp -o compiled/UserController.o

compiled/BookController.o: controller/Source/BookController.cpp controller/Header/BookController.h
	g++ -c controller/Source/BookController.cpp -o compiled/BookController.o

compiled/BookRequestController.o: controller/Source/BookRequestController.cpp controller/Header/BookRequestController.h
	g++ -c controller/Source/BookRequestController.cpp -o compiled/BookRequestController.o

##########################model
compiled/Author.o: model/Source/Author.cpp model/Header/Author.h
	g++ -c model/Source/Author.cpp -o compiled/Author.o
	
compiled/Book.o: model/Source/Book.cpp model/Header/Book.h
	g++ -c model/Source/Book.cpp -o compiled/Book.o

compiled/BookRequest.o: model/Source/BookRequest.cpp model/Header/BookRequest.h
	g++ -c model/Source/BookRequest.cpp -o compiled/BookRequest.o

compiled/Catalog.o: model/Source/Catalog.cpp model/Header/Catalog.h
	g++ -c model/Source/Catalog.cpp -o compiled/Catalog.o

compiled/Data.o: model/Source/Data.cpp model/Header/Data.h
	g++ -c model/Source/Data.cpp -o compiled/Data.o

compiled/Librarian.o: model/Source/Librarian.cpp model/Header/Librarian.h
	g++ -c model/Source/Librarian.cpp -o compiled/Librarian.o

compiled/Member.o: model/Source/Member.cpp model/Header/Member.h
	g++ -c model/Source/Member.cpp -o compiled/Member.o

compiled/User.o: model/Source/User.cpp model/Header/User.h
	g++ -c model/Source/User.cpp -o compiled/User.o
	
all: controller/Header/Controller.h compiled/main.o compiled/View.o compiled/LibrarianView.o compiled/BaseController.o compiled/AuthorController.o compiled/Author.o compiled/Book.o compiled/BookRequest.o compiled/Catalog.o compiled/Data.o compiled/Librarian.o compiled/Member.o compiled/User.o compiled/UserController.o compiled/BookController.o compiled/MemberView.o compiled/MainView.o compiled/BookRequestController.o
	rm -rf app
	g++ compiled/*.o -o app 
	 ./app
	# rm -rf app

reset:
	reset

test:
	g++ main.cpp model/Source/*.cpp view/Source/*.cpp controller/Source/*.cpp
clean:
	rm -rf compiled/*.o
	rm -rf app