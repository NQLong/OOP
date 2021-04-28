#include <bits/stdc++.h>
#include "stringOfVector.h"

using namespace std;

template <typename T>
string StringOfVector(vector<T> input)
{
    string res = "[";
    for (typename vector<T>::iterator i = input.begin(); i != input.end(); i++)
    {
        res += (*i).toString();
        if (i + 1 != input.end())
            res += ",";
    }
    res += "]";
    return res;
}