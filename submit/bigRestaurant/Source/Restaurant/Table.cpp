#include "../../Header/Restaurant/Table.h"

string Table::class_name = "table";

int Table::new_id = 0;

ostream &operator<<(ostream &os, const Table &t)
{
    int title_space = 15;
    return os
           << setw(title_space) << left << "Table id"
           << ": " << t.table_id << endl
           << setw(title_space) << left << "Max capacity"
           << ": " << t.max_acpacity << endl
           << setw(title_space) << left << "Branch id"
           << ": " << t.branch_id << endl
           << setw(title_space) << left << "table status"
           << ": " << (TableStatus)t.status << endl
           << setw(title_space) << left << "Table seats"
           << ": " << endl
           << t.seats;

    ;
}
ostream &operator<<(ostream &os, const list<Table> &lst)
{

    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 65;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    os
        << border << setw(15) << left << "table id"
        << inside_v_border << setw(15) << left << "branch id"
        << inside_v_border << setw(15) << left << "max capacity"
        << inside_v_border << setw(15) << left << "Status" << border << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        os
            << endl
            << border << setw(15) << left << it->table_id
            << inside_v_border << setw(15) << left << it->branch_id
            << inside_v_border << setw(15) << left << it->max_acpacity
            << inside_v_border << setw(15) << left << TableStatus(it->status) << border << endl
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

Table::Table()
    : table_id(new_id++)
{
    this->set_list(&this->seats);
}

Table::~Table() {}

Table::Table(int _location_id, int _branch_id, list<TableSeat> _seats)
    : table_id(new_id++), max_acpacity(_seats.size()), location_id(_location_id), branch_id(_branch_id), seats(_seats)
{
    this->set_list(&this->seats);
}

int Table::selectSeatId()
{
    cout << seats;
    cout << endl;
    cout << "seat number: ";
    int num;
    cin >> num;
    cin.ignore();
    return num;
}

// int Table::selectTableId(int branch)
// {
//     for (auto it = tables.begin(); it != tables.end(); it++)
//         if (it->getBranch_id() == branch)
//             cout
//                 << setw(3) << left << to_string(it->getTable_id()) + "."
//                 << "table's location id: " << it->getLocation_id() << endl
//                 << setw(3) << left << ""
//                 << "table's max capacity : " << it->getMax_acpacity() << endl
//                 << endl;
//     cout << "select table id: ";
//     int id;
//     cin >> id;
//     if (!getTable(id))
//     {
//         cout << "invalid table id";
//         wait();
//         return -1;
//     }
//     cin.ignore();
//     return id;
// }

// void Table::setTables(list<Table> lst)
// {
//     tables = lst;
// }

Table Table::input(int branch_id)
{
    Table temp;
    temp.branch_id = branch_id;
    cout << "table's location id: ";
    cin >> temp.location_id;
    cin.ignore();
    clear();
    while (!select_statement("Add table seats", "Done"))
    {
        clear();
        int new_seat = my_input_c<int>("Number of seat: ");
        if (new_seat <= 0)
        {
            clear();
            cout << "Invalid input";
            wait();
            continue;
        }
        clear();
        SeatType typ = select_seat_type();
        for (int i = 0; i < new_seat; i++)
            temp.add_element(TableSeat(typ));
        temp.max_acpacity += new_seat;
        clear();
    }
    return temp;
}

bool Table::modify_table()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "moidfy max capacity." << endl
            << setw(3) << left << to_string(count++) + "."
            << "moidfy location id." << endl
            << setw(3) << left << to_string(count++) + "."
            << "add seat." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify seat." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "new max capacity :";
            cin >> this->max_acpacity;
            cin.ignore();
            break;
        case 2:
            cout << "new location id :";
            cin >> this->location_id;
            cin.ignore();
            break;
        case 3:
            this->add_seat();
            break;
        case 4:
            this->modify_seat();
            break;
        default:
            loop = false;
            break;
        }
    }

    return true;
}

// bool Table::add_seat(TableSeat seat)
// {
//     seats.push_back(seat);
//     return true;
// }

bool Table::add_seat()
{
    if (ListManager<TableSeat>(&seats).add_element(-1))
    {
        this->max_acpacity++;
        return true;
    }
    return false;
}

TableSeat *Table::pick_seat()
{
    return ListManager<TableSeat>(&seats).pick_element();
}

bool Table::modify_seat()
{
    return true;
}
//getter setter
int Table::getTable_id()
{
    return this->table_id;
}
int Table::get_id()
{
    return this->table_id;
}

void Table::setTable_id(int table_id)
{
    this->table_id = table_id;
}

int Table::getMax_acpacity()
{
    return this->max_acpacity;
}

void Table::setMax_acpacity(int max_acpacity)
{
    this->max_acpacity = max_acpacity;
}

int Table::getLocation_id()
{
    return this->location_id;
}

void Table::setLocation_id(int location_id)
{
    this->location_id = location_id;
}

int Table::getBranch_id()
{
    return this->branch_id;
}

void Table::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}

TableStatus Table::getStatus()
{
    return this->status;
}

void Table::setStatus(TableStatus status)
{
    this->status = status;
}

list<TableSeat> Table::getSeats()
{
    return this->seats;
}

void Table::setSeats(list<TableSeat> seats)
{
    this->seats = seats;
}
