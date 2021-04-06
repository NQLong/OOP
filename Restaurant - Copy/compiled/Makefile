all: main.o

	g++ -o app *.o

main.o: View.o
	g++ -c ../main.cpp -o main.o

View.o:	MealView.o
	g++ -c ../view/View.cpp -o View.o

Restaurant.o: Meal.o
	g++ -c ../controller/restaurant.cpp -o Restaurant.o

Meal.o: ServedDish.o Dish.o IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	g++ -c ../model/Meal.cpp -o Meal.o

ServedDish.o: Dish.o IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	g++ -c ../model/ServedDish.cpp -o ServedDish.o

Dish.o: IngridientQuant.o Ingridient.o Waiter.o Client.o Person.o Table.o
	g++ -c ../model/Dish.cpp -o Dish.o

IngridientQuant.o: Ingridient.o Waiter.o Client.o Person.o Table.o
	g++ -c ../model/IngridientQuant.cpp -o IngridientQuant.o

Ingridient.o: Waiter.o Client.o Person.o Table.o
	g++ -c ../model/Ingridient.cpp -o Ingridient.o

Waiter.o: Client.o Person.o Table.o
	g++ -c ../model/Waiter.cpp -o Waiter.o

Client.o: Person.o Table.o
	g++ -c ../model/Client.cpp -o Client.o

Person.o: Table.o
	g++ -c ../model/Person.cpp -o Person.o

Table.o: 
	g++ -c ../model/Table.cpp -o Table.o

MealView.o: DishView.o IngridientView.o WaiterView.o ClientView.o TableView.o
	g++ -c ../view/MealView.cpp -o MealView.o

DishView.o: IngridientView.o WaiterView.o ClientView.o TableView.o
	g++ -c ../view/DishView.cpp -o DishView.o

IngridientView.o: WaiterView.o ClientView.o TableView.o
	g++ -c ../view/IngridientView.cpp -o IngridientView.o

WaiterView.o: ClientView.o TableView.o
	g++ -c ../view/WaiterView.cpp -o WaiterView.o

ClientView.o: TableView.o
	g++ -c ../view/ClientView.cpp -o ClientView.o

TableView.o: GeneralView.o
	g++ -c ../view/TableView.cpp -o TableView.o

GeneralView.o: Restaurant.o
	g++ -c ../view/GeneralView.cpp -o GeneralView.o

cleanView:
	rm -rf *View.o

cleanC:
	rm -rf Restaurant.o

clean:
	rm -rf *.o