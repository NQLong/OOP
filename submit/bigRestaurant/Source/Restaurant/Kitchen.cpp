#include "../../Header/Restaurant/Kitchen.h"

Kitchen::~Kitchen(){}


Kitchen Kitchen::inputKitchen(){
    Kitchen temp;
    cout<<"Kitchen's name: ";
    getline(cin,temp.name);
    return temp;
}