all: compiled/Menu.o compiled/Admin.o compiled/Chef.o compiled/Receptionist.o compiled/Waiter.o compiled/View.o compiled/main.o compiled/Manager.o compiled/Person.o compiled/Employee.o compiled/Account.o compiled/Restaurant.o  compiled/constraint.o compiled/Branch.o compiled/Kitchen.o
	g++ compiled/*.o -o app

compiled/main.o: main.cpp
	g++ -c main.cpp -o compiled/main.o



compiled/View.o: View/Source/View.cpp View/Header/View.h
	g++ -c View/Source/View.cpp -o compiled/View.o



compiled/constraint.o : Constraint/constraint.h Constraint/constraint.cpp
	g++ -c Constraint/constraint.cpp -o compiled/constraint.o


compiled/Admin.o: Actor/Source/Admin.cpp Actor/Header/Admin.h
	g++ -c Actor/Source/Admin.cpp -o compiled/Admin.o

compiled/Chef.o: Actor/Source/Chef.cpp Actor/Header/Chef.h
	g++ -c Actor/Source/Chef.cpp -o compiled/Chef.o

compiled/Receptionist.o: Actor/Source/Receptionist.cpp Actor/Header/Receptionist.h
	g++ -c Actor/Source/Receptionist.cpp -o compiled/Receptionist.o

compiled/Waiter.o: Actor/Source/Waiter.cpp Actor/Header/Waiter.h
	g++ -c Actor/Source/Waiter.cpp -o compiled/Waiter.o

compiled/Person.o: Actor/Source/Person.cpp Actor/Header/Person.h
	g++ -c Actor/Source/Person.cpp -o compiled/Person.o

compiled/Manager.o: Actor/Source/Manager.cpp Actor/Header/Manager.h
	g++ -c Actor/Source/Manager.cpp -o compiled/Manager.o

compiled/Employee.o: Actor/Source/Employee.cpp Actor/Header/Employee.h
	g++ -c Actor/Source/Employee.cpp -o compiled/Employee.o

compiled/Account.o: Actor/Source/Account.cpp Actor/Header/Account.h
	g++ -c Actor/Source/Account.cpp -o compiled/Account.o





compiled/Menu.o: Menu/Source/Menu.cpp Menu/Header/Menu.h
	g++ -c Menu/Source/Menu.cpp -o compiled/Menu.o

compiled/Restaurant.o: Restaurant/Source/Restaurant.cpp Restaurant/Header/Restaurant.h
	g++ -c Restaurant/Source/Restaurant.cpp -o compiled/Restaurant.o

compiled/Branch.o: Restaurant/Source/Branch.cpp Restaurant/Header/Branch.h
	g++ -c Restaurant/Source/Branch.cpp -o compiled/Branch.o

compiled/Kitchen.o: Restaurant/Source/Kitchen.cpp Restaurant/Header/Kitchen.h
	g++ -c Restaurant/Source/Kitchen.cpp -o compiled/Kitchen.o

clean:
	rm -rf compiled/*.o
	reset