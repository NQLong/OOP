#include "../../Header/Constraint/MyTime.h"

Day::Day()
{
    reset();
}
Day::~Day() {}

Day::Day(tm _time)
{
    this->_time = _time;
}
Day::Day(time_t _time)
{
    this->_time = *localtime(&_time);
}

tm Day::get_time()
{
    return _time;
}
void Day::set_time(tm _time)
{
    this->_time = _time;
}

void Day::now()
{
    time_t n = time(0);
    this->_time = *localtime(&n);
}

void Day::reset()
{
    time_t n = 0;
    this->_time = *gmtime(&n);
}
void Day::check()
{
    time_t now = mktime(&_time);
    this->_time = *localtime(&now);
}
void Day::input()
{
    int day, month, year;
    cout << "Day : ";
    cin >> _time.tm_mday;
    cout << "Month : ";
    cin >> month;
    _time.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    _time.tm_year = year - 1900;
    cin.ignore();
}

bool Day::add_month(int a)
{
    _time.tm_mon += a;
    check();
    return true;
}
bool Day::add_day(int a)
{
    _time.tm_mday += a;
    check();
    return true;
}
bool Day::add_year(int a)
{
    _time.tm_year += a;
    check();
    return true;
}

ostream &operator<<(ostream &os, const Day &_time)
{
    switch (_time._time.tm_wday)
    {
    case 0:
        os << "Mon";
        break;
    case 1:
        os << "Tue";
        break;
    case 2:
        os << "Wed";
        break;
    case 3:
        os << "Thu";
        break;
    case 4:
        os << "Fri";
        break;
    case 5:
        os << "Sat";
        break;
    case 6:
        os << "Sun";
        break;
    }
    os << ", " << _time._time.tm_mday << "-";
    switch (_time._time.tm_mon)
    {
    case 0:
        os << "Jan";
        break;
    case 1:
        os << "Feb";
        break;
    case 2:
        os << "Mar";
        break;
    case 3:
        os << "Apr";
        break;
    case 4:
        os << "May";
        break;
    case 5:
        os << "Jun";
        break;
    case 6:
        os << "Jul";
        break;
    case 7:
        os << "Aug";
        break;
    case 8:
        os << "Sep";
        break;
    case 9:
        os << "Oct";
        break;
    case 10:
        os << "Nov";
        break;
    case 11:
        os << "Dec";
        break;
    }
    return os << "-" << 1900 + _time._time.tm_year;
}

DayTime::DayTime() : Day()
{
}
DayTime::~DayTime() {}
DayTime::DayTime(tm _time) : Day(_time) {}
DayTime::DayTime(time_t _time) : Day(_time) {}

bool DayTime::add_sec(int a)
{
    _time.tm_sec += a;
    check();
    return true;
}
bool DayTime::add_min(int a)
{
    _time.tm_min += a;
    check();
    return true;
}
bool DayTime::add_hour(int a)
{
    _time.tm_hour += a;
    check();
    return true;
}

ostream &operator<<(ostream &os, const DayTime &_time)
{
    DayTime t = _time;
    os << Day(_time._time)
       << ", ";
    if (_time._time.tm_hour < 10)
        os << 0;
    os << _time._time.tm_hour << ":";
    if (_time._time.tm_min < 10)
        os << 0;
    os << _time._time.tm_min << ":";
    if (_time._time.tm_sec < 10)
        os << 0;
    os << _time._time.tm_sec;

    return os;
}

DayTime DayTime::input_time()
{
    DayTime temp = input_date();
    cout << "Hour: ";
    cin >> temp._time.tm_hour;
    cout << "Min : ";
    cin >> temp._time.tm_min;
    cout << "Seccond: ";
    cin >> temp._time.tm_sec;
    cin.ignore();
    temp.check();
    return temp;
}

DayTime DayTime::input_date()
{
    DayTime temp;
    temp.input();
    temp.check();
    return temp;
}


bool operator==(const DayTime &lhs, const DayTime &rhs){
    return (
        (rhs._time == lhs._time) && 
        true
    );
}