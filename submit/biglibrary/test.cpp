#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
string lower_string(string in)
{
    string data = in;
    transform(data.begin(), data.end(), data.begin(),
              [](unsigned char c) { return tolower(c); });
    return data;
}

int main()
{
    // string a = "ADASD123!@##@$";
    // cout<<a<<endl;
    // cout<<lower_string(a)<<endl;
    // cout<<a<<endl;
    stringstream ss;
    ss
        << " abc "
        << "def " << endl
        << " abcasd "
        << "defasdasd " << endl;
    string res;
    string temp;
    while (!ss.eof())
    {
        getline(ss,temp,'\0');
        res += temp;
    }
    cout<<res;
}