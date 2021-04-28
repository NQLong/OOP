all: main.o
	gcc main.o

main.o: Meal.o ServedDish.o Dish.o IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	gcc -c model/main.cpp -o compiled/main.o

Meal.o: ServedDish.o Dish.o IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	gcc -c model/Meal.cpp -o compiled/Meal.o

ServedDish.o: Dish.o IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	gcc -c model/ServedDish.cpp -o compiled/ServedDish.o

Dish.o: IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	gcc -c model/Dish.cpp -o compiled/Dish.o

IngridientQuant.o: Ingridient.o Waiter.o Client.o Person.o Table.o
	gcc -c model/IngridientQuant.cpp -o compiled/IngridientQuant.o

Ingridient.o: Waiter.o Client.o Person.o Table.o
	gcc -c model/Ingridient.cpp -o compiled/Ingridient.o

Waiter.o: Client.o Person.o Table.o
	gcc -c model/Waiter.cpp -o compiled/Waiter.o

Client.o: Person.o Table.o
	gcc -c model/Client.cpp -o compiled/Client.o

Person.o: Table.o
	gcc -c model/Person.cpp -o compiled/Person.o

Table.o: 
	gcc -c model/Table.cpp -o compiled/Table.o