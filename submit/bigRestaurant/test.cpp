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
    stringstream ss;
    string s = "lkasjdlkasjdlasjdl : asdj asdkjaskldjlasjd\n1 : 2";
    ss << setw(20)<<""<<s;
    string temp;
    while (!ss.eof()){
        getline(ss,temp,':');
        cout<<"|"<<temp<<"|";
        getline(ss,temp);
        cout<<temp<<endl;
    }

}