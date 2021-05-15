#ifndef D0982D4E_1767_42A4_AC60_877DDAC797FB
#define D0982D4E_1767_42A4_AC60_877DDAC797FB

#include <ctime>
#include <iostream>

using namespace std;
class Day
{
private:
public:
    tm _time;
    Day();
    ~Day();
    Day(tm _time);
    Day(time_t _time);

    tm get_time();
    void set_time(tm _time);

    void reset();
    void check();
    void input();

    void now();

    bool add_month(int);
    bool add_day(int);
    bool add_year(int);

    friend ostream &operator<<(ostream &os, const Day &);
};

class DayTime : public Day
{
public:
    DayTime();
    ~DayTime();
    DayTime(tm _time);
    DayTime(time_t _time);

    bool add_sec(int);
    bool add_min(int);
    bool add_hour(int);

    static DayTime input_time();

    static DayTime input_date();

    friend ostream &operator<<(ostream &os, const DayTime &);
    friend bool operator==(const DayTime &lhs, const DayTime &rhs);
    
};

#endif /* D0982D4E_1767_42A4_AC60_877DDAC797FB */
