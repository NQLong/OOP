all: compiled/Customer.o compiled/Reservation.o compiled/CreditCardTransaction.o compiled/CheckTransaction.o compiled/CashTransaction.o compiled/Payment.o compiled/Check.o compiled/MealItem.o compiled/Meal.o compiled/Order.o compiled/Table.o compiled/TableSeat.o compiled/MenuItem.o compiled/MenuSection.o compiled/Menu.o compiled/Admin.o compiled/Chef.o compiled/Receptionist.o compiled/Waiter.o compiled/View.o compiled/main.o compiled/Manager.o compiled/Person.o compiled/Employee.o compiled/Account.o compiled/Restaurant.o  compiled/constraint.o compiled/Branch.o compiled/Kitchen.o
	g++ compiled/*.o -o app

compiled/main.o: main.cpp
	g++ -c main.cpp -o compiled/main.o



compiled/View.o: Source/View/View.cpp Header/View/View.h
	g++ -c Source/View/View.cpp -o compiled/View.o



compiled/constraint.o : Header/Constraint/constraint.h Source/Constraint/constraint.cpp
	g++ -c Source/Constraint/constraint.cpp -o compiled/constraint.o


compiled/Admin.o: Source/Actor/Admin.cpp Header/Actor/Admin.h
	g++ -c Source/Actor/Admin.cpp -o compiled/Admin.o

compiled/Chef.o: Source/Actor/Chef.cpp Header/Actor/Chef.h
	g++ -c Source/Actor/Chef.cpp -o compiled/Chef.o

compiled/Receptionist.o: Source/Actor/Receptionist.cpp Header/Actor/Receptionist.h
	g++ -c Source/Actor/Receptionist.cpp -o compiled/Receptionist.o

compiled/Waiter.o: Source/Actor/Waiter.cpp Header/Actor/Waiter.h
	g++ -c Source/Actor/Waiter.cpp -o compiled/Waiter.o

compiled/Person.o: Source/Actor/Person.cpp Header/Actor/Person.h
	g++ -c Source/Actor/Person.cpp -o compiled/Person.o

compiled/Manager.o: Source/Actor/Manager.cpp Header/Actor/Manager.h
	g++ -c Source/Actor/Manager.cpp -o compiled/Manager.o

compiled/Employee.o: Source/Actor/Employee.cpp Header/Actor/Employee.h
	g++ -c Source/Actor/Employee.cpp -o compiled/Employee.o

compiled/Account.o: Source/Actor/Account.cpp Header/Actor/Account.h
	g++ -c Source/Actor/Account.cpp -o compiled/Account.o

compiled/Customer.o: Source/Actor/Customer.cpp Header/Actor/Customer.h
	g++ -c Source/Actor/Customer.cpp -o compiled/Customer.o




compiled/Reservation.o: Source/Reservation/Reservation.cpp Header/Reservation/Reservation.h
	g++ -c Source/Reservation/Reservation.cpp -o compiled/Reservation.o



compiled/Menu.o: Source/Menu/Menu.cpp Header/Menu/Menu.h
	g++ -c Source/Menu/Menu.cpp -o compiled/Menu.o

compiled/MenuSection.o: Source/Menu/MenuSection.cpp Header/Menu/MenuSection.h
	g++ -c Source/Menu/MenuSection.cpp -o compiled/MenuSection.o

compiled/MenuItem.o: Source/Menu/MenuItem.cpp Header/Menu/MenuItem.h
	g++ -c Source/Menu/MenuItem.cpp -o compiled/MenuItem.o





compiled/Payment.o: Source/Check/Payment.cpp Header/Check/Payment.h
	g++ -c Source/Check/Payment.cpp -o compiled/Payment.o

compiled/CreditCardTransaction.o: Source/Check/CreditCardTransaction.cpp Header/Check/CreditCardTransaction.h
	g++ -c Source/Check/CreditCardTransaction.cpp -o compiled/CreditCardTransaction.o

compiled/CheckTransaction.o: Source/Check/CheckTransaction.cpp Header/Check/CheckTransaction.h
	g++ -c Source/Check/CheckTransaction.cpp -o compiled/CheckTransaction.o

compiled/CashTransaction.o: Source/Check/CashTransaction.cpp Header/Check/CashTransaction.h
	g++ -c Source/Check/CashTransaction.cpp -o compiled/CashTransaction.o

compiled/Check.o: Source/Check/Check.cpp Header/Check/Check.h
	g++ -c Source/Check/Check.cpp -o compiled/Check.o







compiled/MealItem.o: Source/Meal/MealItem.cpp Header/Meal/MealItem.h
	g++ -c Source/Meal/MealItem.cpp -o compiled/MealItem.o

compiled/Meal.o: Source/Meal/Meal.cpp Header/Meal/Meal.h
	g++ -c Source/Meal/Meal.cpp -o compiled/Meal.o






compiled/Order.o: Source/Order/Order.cpp Header/Order/Order.h
	g++ -c Source/Order/Order.cpp -o compiled/Order.o




compiled/TableSeat.o: Source/Restaurant/TableSeat.cpp Header/Restaurant/TableSeat.h
	g++ -c Source/Restaurant/TableSeat.cpp -o compiled/TableSeat.o

compiled/Table.o: Source/Restaurant/Table.cpp Header/Restaurant/Table.h
	g++ -c Source/Restaurant/Table.cpp -o compiled/Table.o

compiled/Restaurant.o: Source/Restaurant/Restaurant.cpp Header/Restaurant/Restaurant.h
	g++ -c Source/Restaurant/Restaurant.cpp -o compiled/Restaurant.o

compiled/Branch.o: Source/Restaurant/Branch.cpp Header/Restaurant/Branch.h
	g++ -c Source/Restaurant/Branch.cpp -o compiled/Branch.o

compiled/Kitchen.o: Source/Restaurant/Kitchen.cpp Header/Restaurant/Kitchen.h
	g++ -c Source/Restaurant/Kitchen.cpp -o compiled/Kitchen.o

clean:
	rm -rf compiled/*.o
	reset