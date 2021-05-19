#include "../../Header/Restaurant/TableSeat.h"

TableSeat::TableSeat() {}

TableSeat::~TableSeat() {}

TableSeat TableSeat::input_table_seat(int branch, int table)
{
    TableSeat temp;
    temp.branch_id = branch;
    temp.table_id = table;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(3) << to_string(i + 1) + "." << (SeatType)(i) << endl;
    }
    cout << endl
         << "Seat type: ";
    int option;
    cin >> option;
    if (option >= 1 && option <= 4)
        temp.Typ = (SeatType)(option - 1);
    return temp;
}

int TableSeat::getTable_seat_number()
{
    return this->table_seat_number;
}

void TableSeat::setTable_seat_number(int table_seat_number)
{
    this->table_seat_number = table_seat_number;
}

SeatType TableSeat::getTyp()
{
    return this->Typ;
}

void TableSeat::setTyp(SeatType Typ)
{
    this->Typ = Typ;
}

int TableSeat::getBranch_id()
{
    return this->branch_id;
}

void TableSeat::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}

int TableSeat::getTable_id()
{
    return this->table_id;
}

void TableSeat::setTable_id(int table_id)
{
    this->table_id = table_id;
}

ostream &operator<<(ostream &os, const TableSeat &seat)
{
    os << seat.table_seat_number<<". "<<seat.Typ;
    return os;
}