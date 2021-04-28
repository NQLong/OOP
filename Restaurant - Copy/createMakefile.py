modelNames = ["Meal", "ServedDish", "Dish", "IngridientQuant",
              "Ingridient", "Waiter", "Client", "Person", "Table"]
# f = open("Makefile2", "w+")

viewNames = ["Meal", "Dish",
             "Ingridient", "Waiter", "Client", "Table"]

controllerNames = ["Meal", "Dish",
                   "Ingridient", "Waiter", "Client", "Table"]


for i,name in enumerate(controllerNames):
    # print(name+"Controller*","get"+name+"Controller();")
    temp = [*controllerNames]
    temp.remove(name)
    print("this->"+name[0].lower() +name[1:]+"Controller->config("+"Controller, ".join([key[0].lower() +key[1:] for key in temp])+"Controller" +");")
    print()
# for i, name in enumerate(modelNames):
#     print(name, ".o: ", " ".join(
#         [key+".o" for key in modelNames[i+1:]]), sep="")
#     print("    gcc -c model/", name, ".cpp -o compiled/", name, ".o", sep="")
#     print()
#     # if name == "Meal":

# for i, name in enumerate(controllerNames):
#     print(name, "Controller.o: ", " ".join(
#         [key+"Controller.o" for key in controllerNames[i+1:]]), sep="",end="")
#     print("Meal.o" if name == "Table" else "")
#     print("    gcc -c controller/", name, "Controller.cpp -o compiled/", name, "Controller.o", sep="")
#     print()

# for i, name in enumerate(viewNames):
#     print(name, "View.o: ", " ".join(
#         [key+"View.o" for key in viewNames[i+1:]]), sep="",end="")
#     print("MealController.o" if name == "Table" else "")
#     print("    gcc -c view/", name, "View.cpp -o compiled/", name, "View.o", sep="")
#     print()
# f.close()
