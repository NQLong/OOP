#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <list>
#include <sstream>

#include "test.h"
using namespace std;

int main()
{
    for (int i = 0; i < 255; i++)
        cout << setw(4) << left << i << '¤' << endl;
}