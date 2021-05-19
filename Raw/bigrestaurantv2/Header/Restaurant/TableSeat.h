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
    int branch_id;
    int table_id;

    
    

public:
    TableSeat();
    ~TableSeat();
    TableSeat(int _table_seat_number, int _branch_id, int _table_id) : table_seat_number(_table_seat_number), branch_id(_branch_id), table_id(_table_id) {}
    TableSeat(int _table_seat_number, SeatType _Typ, int _branch_id, int _table_id) : table_seat_number(_table_seat_number), Typ(_Typ), branch_id(_branch_id), table_id(_table_id) {}

    static TableSeat input_table_seat(int branch, int table);

    bool update_seat_type(SeatType);


    int getTable_seat_number();
    void setTable_seat_number(int table_seat_number);
    SeatType getTyp();
    void setTyp(SeatType Typ);
    int getBranch_id();
    void setBranch_id(int branch_id);
    int getTable_id();
    void setTable_id(int table_id);

    friend ostream& operator<<(ostream& os, const TableSeat& seat);
};


#endif /* CC8C9474_A51E_4437_B9E3_8881E9452129 */
