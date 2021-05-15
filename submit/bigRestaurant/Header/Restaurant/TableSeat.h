#ifndef CC8C9474_A51E_4437_B9E3_8881E9452129
#define CC8C9474_A51E_4437_B9E3_8881E9452129

// class TableSeat:
//     def __init__(self):
//         self.__table_seat_number = 0
//         self.__type = SeatType.REGULAR

//     def update_seat_type(self, seat_type):
//         None
#include "../../Header/Constraint/constraint.h"
#include <iomanip>
#include <iostream>

class TableSeat
{
private:
    int table_seat_number;
    SeatType Typ = S_REGULAR;

    static int new_number;

public:
    static string class_name;

    friend bool operator==(const TableSeat &lhs, const TableSeat &rhs)
    {
        return (
            (lhs.table_seat_number == rhs.table_seat_number) &&
            (lhs.Typ == rhs.Typ) &&
            true

        );
    }

    ~TableSeat();
    TableSeat() :  table_seat_number(new_number++) {}
    TableSeat(SeatType _Typ) : Typ(_Typ), table_seat_number(new_number++) {}

    static TableSeat input(int table);

    bool update_seat_type(SeatType);

    int getTable_seat_number();
    int get_id();
    void setTable_seat_number(int table_seat_number);
    SeatType getTyp();
    void setTyp(SeatType Typ);

    friend ostream &operator<<(ostream &os, const TableSeat &seat);
    friend ostream &operator<<(ostream &, const list<TableSeat> &);
};

#endif /* CC8C9474_A51E_4437_B9E3_8881E9452129 */
