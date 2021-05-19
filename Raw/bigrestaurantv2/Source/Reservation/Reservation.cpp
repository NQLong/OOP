#include "../../Header/Reservation/Reservation.h"

Reservation::Reservation() {}
Reservation::~Reservation() {}

bool Reservation::add_reservation(Reservation r)
{
    reservations.push_back(r);
    return true;
}

int input_customer()
{
    int count = 1;
    clear();

    cout
        << setw(3) << left << to_string(count++) + "."
        << "Register new customer." << endl
        << setw(3) << left << to_string(count++) + "."
        << "Get existing account." << endl;
    cout << endl
         << "your choice: ";
    int option;
    cin >> option;
    cin.ignore();
    Customer c;
    switch (option)
    {
    case 1:
        clear();
        c = Customer::input_customer();
        c.setCustomerId(Customer::getCustomers()->size() > 0 ? Customer::getCustomers()->back().getCustomerId() + 1 : 0);
        Customer::add_customer(c);
        return c.getCustomerId();
    case 2:
        clear();
        return Customer::select_customer_id();
    }
    return -1;
}

list<int> input_table_ids(int branch_id)
{
    list<int> temp;
    bool loop = true;
    int option;
    int id;
    while (loop)
    {
        clear();
        cout << "1. add table" << endl
             << "2. done" << endl;

        cout << endl
             << "your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            cout << "pick table:" << endl
                 << endl;
            id = Table::selectTableId(branch_id);
            if (id != -1)
                if (!is_consist(temp, id))
                    temp.push_back(id);
                else
                {
                    cout << "Table already pick";
                    wait();
                }
            break;
        default:
            return temp;
        }
    }
    return temp;
}

Reservation Reservation::input_reservation(int branch_id)
{
    Reservation temp;
    clear();
    cout << "select customer: " << endl;
    temp.customer_id = input_customer();
    clear();
    cout << "People count: ";
    cin >> temp.people_count;
    cin.ignore();
    temp.table_ids = input_table_ids(branch_id);
    clear();
    cout << "take notes: ";
    getline(cin, temp.notes);
    clear();
    cout << "time of reservation: "<<endl;
    temp.time_of_reservation = input_time();
    while (!is_valid_date(temp.time_of_reservation))
    {
        cout << "invalid reservation time, try again";
        wait();
        clear();
        cout << "time of reservation: "<<endl;
    }
    return temp;
}

//getter setter
list<Reservation> Reservation::reservations;

int Reservation::getReservation_id()
{
    return this->reservation_id;
}

void Reservation::setReservation_id(int reservation_id)
{
    this->reservation_id = reservation_id;
}

time_t Reservation::getTime_of_reservation()
{
    return this->time_of_reservation;
}

void Reservation::setTime_of_reservation(time_t time_of_reservation)
{
    this->time_of_reservation = time_of_reservation;
}

int Reservation::getPeople_count()
{
    return this->people_count;
}

void Reservation::setPeople_count(int people_count)
{
    this->people_count = people_count;
}

ReservationStatus Reservation::getStatus()
{
    return this->status;
}

void Reservation::setStatus(ReservationStatus status)
{
    this->status = status;
}

string Reservation::getNotes()
{
    return this->notes;
}

void Reservation::setNotes(string notes)
{
    this->notes = notes;
}

time_t Reservation::getCheckin_time()
{
    return this->checkin_time;
}

void Reservation::setCheckin_time(time_t checkin_time)
{
    this->checkin_time = checkin_time;
}

int Reservation::getCustomer_id()
{
    return this->customer_id;
}

void Reservation::setCustomer_id(int customer_id)
{
    this->customer_id = customer_id;
}

list<int> Reservation::getTable_ids()
{
    return this->table_ids;
}

void Reservation::setTable_ids(list<int> table_ids)
{
    this->table_ids = table_ids;
}

list<int> Reservation::getNotification_ids()
{
    return this->notification_ids;
}

void Reservation::setNotification_ids(list<int> notification_ids)
{
    this->notification_ids = notification_ids;
}

list<Reservation> *Reservation::getReservations()
{
    return &reservations;
}

void Reservation::setReservations(list<Reservation> _reservations)
{
    reservations = _reservations;
}
