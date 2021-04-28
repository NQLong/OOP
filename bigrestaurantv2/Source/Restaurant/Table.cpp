#include "../../Header/Restaurant/Table.h"
list<Table> Table::tables;

Table::Table() {}

Table::~Table() {}

int Table::selectSeatId(){
    for (auto it = seats.begin(); it != seats.end(); it++)
        cout<<*it<<endl;
    cout<<endl;
    cout<<"seat number: ";
    int num;
    cin>>num;
    

    return num;

    
}

bool Table::addTable(Table t)
{
    tables.push_back(t);
    return true;
}

Table *Table::getTable(int id)
{
    for (auto it = tables.begin(); it != tables.end(); it++)
        if (it->getTable_id() == id)
            return &(*it);
    return NULL;
}

list<Table> *Table::getTables()
{
    return &tables;
}

int Table::selectTableId(int branch)
{
    for (auto it = tables.begin(); it != tables.end(); it++)
        if (it->getBranch_id() == branch)
            cout
                << setw(3) << left << to_string(it->getTable_id()) + "."
                << "table's location id: " << it->getLocation_id() << endl
                << setw(3) << left << ""
                << "table's max capacity : " << it->getMax_acpacity() << endl
                << endl;
    cout << "select table id: ";
    int id;
    cin >> id;
    if (!getTable(id)){
        cout<<"invalid table id";
        wait();
        return -1;
    }
    cin.ignore();
    return id;
}

void Table::setTables(list<Table> lst)
{
    tables = lst;
}

Table Table::inputTable(int branch_id)
{
    Table temp;
    temp.branch_id = branch_id;
    cout << "Table's max capacity: ";
    cin >> temp.max_acpacity;
    cout << "table's location id: ";
    cin >> temp.location_id;
    cin.ignore();
    return temp;
}

bool Table::modify_table()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        system("clear");

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

bool Table::add_seat(TableSeat seat){
    seats.push_back(seat);
    return true;
}

bool Table::add_seat()
{
    if (this->seats.size() >= this->max_acpacity)
    {
        cout << "table reach max capacity";
        wait();
        return false;
    }
    system("clear");
    TableSeat seat = TableSeat::input_table_seat(this->branch_id, this->table_id);
    int id = seats.size()> 0? seats.back().getTable_seat_number() + 1: 0;
    return add_seat(seat);
}

bool Table::modify_seat(){
    return true;
}
//getter setter
int Table::getTable_id()
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
