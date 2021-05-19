#include "../../Header/Restaurant/TableSeat.h"

string TableSeat::class_name = "table seat";

int TableSeat::new_number = 0;

TableSeat::~TableSeat() {}

TableSeat TableSeat::input(int table)
{
    TableSeat temp;
    temp.Typ = select_seat_type();
    return temp;
}

int TableSeat::getTable_seat_number()
{
    return this->table_seat_number;
}

int TableSeat::get_id()
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

ostream &operator<<(ostream &os, const TableSeat &seat)
{
    os
        << setw(15) << "Seat Number"
        << ": " << seat.table_seat_number << endl
        << setw(15) << "Seat Type"
        << ": " << (SeatType)seat.Typ;
    // os
    // <<
    //  seat.table_seat_number << ". " << seat.Typ;
    return os;
}

ostream &operator<<(ostream &os, const list<TableSeat> &lst)
{

    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 35;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    os
        << border << setw(12) << left << "seat number"
        << "|" << setw(20) << left << "seat type" << border << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    ;
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        os
            << endl
            << border << setw(12) << left << it->table_seat_number
            << "|" << setw(20) << left << (SeatType)it->Typ << border << endl
            << border << setw(border_size - 2) << setfill(inside_h_border) << "" << border
            << setfill(' ');
        ;
    }
    os
        << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    return os;
}