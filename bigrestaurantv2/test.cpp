#include <bits/stdc++.h>

using namespace std;

bool is_valid_date(time_t t)
{
    return (t < time(0) && (t - time(0))/3600/24 < 7); 
}

time_t input_time()
{
    int day, month, year;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    cout << "Day : ";
    cin >> ltm.tm_mday;
    cout << "Month : ";
    cin >> month;
    ltm.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    ltm.tm_year = year - 1900;
    cin.ignore();
    return mktime(&ltm);
}

int main()
{
    time_t t = input_time();
    cout << (char *)ctime(&t);
    cout<<is_valid_date(t);
}