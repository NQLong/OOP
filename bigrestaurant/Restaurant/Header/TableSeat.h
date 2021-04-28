#ifndef CC8C9474_A51E_4437_B9E3_8881E9452129
#define CC8C9474_A51E_4437_B9E3_8881E9452129

// class TableSeat:
//     def __init__(self):
//         self.__table_seat_number = 0
//         self.__type = SeatType.REGULAR

//     def update_seat_type(self, seat_type):
//         None
#include "../../Constraint/constraint.h"

class TableSeat
{
private:
    int table_seat_number;
    SeatType Typ = S_REGULAR;

public:
    bool update_seat_type(SeatType);
};

#endif /* CC8C9474_A51E_4437_B9E3_8881E9452129 */
