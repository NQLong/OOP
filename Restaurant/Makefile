all: client.o table.o servedDish.o person.o waiter.o meal.o dish.o ingridient.o main.o IngridientQuant.o
	g++ -Wall *.o -o app

main.o: view.o
	g++ -Wall -c main.cpp

view.o:restaurant.o
	g++ -Wall -c view/view.cpp
restaurant.o: meal.o
	g++ -Wall -c controller/restaurant.cpp
ingridient.o:
	g++ -Wall -c model/ingridient.cpp

IngridientQuant.o: ingridient.o
	g++ -Wall -c model/IngridientQuant.cpp

dish.o:ingridient.o IngridientQuant.o
	g++ -Wall -c model/dish.cpp

table.o:
	g++ -Wall -c model/table.cpp

person.o:
	g++ -Wall -c model/person.cpp

client.o: person.o
	g++ -Wall -c model/client.cpp

waiter.o: person.o
	g++ -Wall -c model/waiter.cpp

servedDish.o: dish.o
	g++ -Wall -c model/servedDish.cpp

meal.o: servedDish.o client.o waiter.o table.o
	g++ -Wall -c model/meal.cpp


clean:
	rm -rf *.o
	rm restaurant

clean2:
	rm app
	rm view.o
	rm restaurant.o