#include "../../Header/Reservation/Reservation.h"

int Reservation::new_id = 0;
string Reservation ::class_name = "reservation";
Reservation::Reservation()
    : reservation_id(new_id++)
{
}

Reservation::~Reservation() {}

ostream &operator<<(ostream &os, const list<Reservation> &lst)
{
    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 104;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    os
        << border << setw(7) << left << " id"
        << inside_v_border << setw(10) << left << "branch id"
        << inside_v_border << setw(15) << left << " People"
        << inside_v_border << setw(30) << left << " Reservation time"
        << inside_v_border << setw(20) << left << " tables"
        << inside_v_border << setw(15) << left << "Status" << border << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        stringstream rs;
        rs << it->time_of_reservation;
        string rss;
        getline(rs, rss);
        os
            << endl
            << border << setw(7) << left << it->reservation_id
            << inside_v_border << setw(10) << left << it->branch_id
            << inside_v_border << setw(15) << left << it->people_count
            << inside_v_border << setw(30) << left << rss
            << inside_v_border << setw(20) << left << string_of_list(it->table_ids)
            << inside_v_border << setw(15) << left << ReservationStatus(it->status) << border << endl
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

ostream &operator<<(ostream &os, const Reservation &r)
{
    int space = 20;
    os
        << setw(space) << left << "Reservation id"
        << ": " << r.reservation_id << endl
        << setw(space) << left << "Branch id"
        << ": " << r.branch_id << endl
        << setw(space) << left << "Nums of People"
        << ": " << r.people_count << endl
        << setw(space) << left << "Duration"
        << ": " << r.duration << " hour(s)" << endl
        << setw(space) << left << "Reservation time"
        << ": " << r.time_of_reservation << endl
        << setw(space) << left << "Checkin time"
        << ": ";
    if (r.checkin_time == DayTime(0))
        os << "Unknown";
    else
        os << r.checkin_time;
    os
        << endl
        << setw(space) << left << "Customer id"
        << ": " << r.customer_id << endl
        << setw(space) << left << "Tables "
        << ": " << string_of_list(r.table_ids) << endl
        << setw(space) << left << "Notifications"
        << ": " << string_of_list(r.notification_ids) << endl

        ;
    return os;
}
bool operator==(const Reservation &, const Reservation &)
{
    return true;
}
Reservation::Reservation(
    time_t _time_of_reservation,
    int _people_count,
    ReservationStatus _status,
    string _notes,
    time_t _checkin_time,
    int _customer_id,
    list<int> _table_ids,
    list<int> _notification_ids,
    int branch,
    int _duration)

    : branch_id(branch),
      reservation_id(new_id++),
      time_of_reservation(_time_of_reservation),
      people_count(_people_count),
      status(_status),
      notes(_notes),
      checkin_time(_checkin_time),
      customer_id(_customer_id),
      table_ids(_table_ids),
      notification_ids(_notification_ids),
      duration(_duration)
{
}

Reservation Reservation::input(int branch_id)
{
    Reservation temp;
    temp.branch_id = branch_id;
    temp.people_count = my_input_c<int>("number of people: ");
    clear();
    temp.duration = my_input_c<int>("duration: ");
    clear();
    temp.time_of_reservation = DayTime::input_time();
    clear();
    temp.notes = input_str("Any note:");
    return temp;
}

bool Reservation::confirm()
{
    if (this->status == R_PENDING)
    {
        TableManager t_man(Storage::tables);
        while (!is_confirmable())
        {
            clear();
            cout << "this reservation is not ready to confirm (lack of "
                 << this->people_count - total_seat() << ")" << endl;
            if (!select_statement("add a table", "cancel"))
            {
                clear();
                int table_id = t_man.pick_free_table(this->branch_id, this->getTime_of_reservation(), this->duration, false);
                if (table_id != -1)
                {
                    if (!is_consist<int>(this->table_ids, table_id))
                        this->table_ids.push_back(table_id);
                    else
                    {
                        cout << "table already included";
                        wait();
                    }
                }
            }
            else
            {
                this->table_ids = {};
                cout << "cacel";
                return false;
            }
        }
        this->setStatus(R_CONFIRMED);
        return true;
    }
    cout << "Invalid action";
    return false;
}

bool Reservation::is_colided(Reservation *other)
{
    return true;
}

int Reservation::total_seat()
{
    int sum = 0;
    TableManager t_man = TableManager(Storage::tables);
    for (auto it = this->table_ids.begin(); it != this->table_ids.end(); it++)
    {
        Table *ptr = t_man.get_element(*it);
        if (ptr)
        {
            sum += ptr->getMax_acpacity();
        }
    }
    return sum;
}

bool Reservation::is_confirmable()
{
    return this->people_count <= total_seat();
}

int Reservation::getReservation_id()
{
    return this->reservation_id;
}

void Reservation::setReservation_id(int reservation_id)
{
    this->reservation_id = reservation_id;
}

DayTime Reservation::getTime_of_reservation()
{
    return this->time_of_reservation;
}

void Reservation::setTime_of_reservation(DayTime time_of_reservation)
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

DayTime Reservation::getCheckin_time()
{
    return this->checkin_time;
}

void Reservation::setCheckin_time(DayTime checkin_time)
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

int Reservation::get_branch_id()
{
    return branch_id;
}
void Reservation::set_branch_id(int branch_id)
{
    this->branch_id = branch_id;
}

int Reservation::get_duration()
{
    return this->duration;
}

void Reservation::set_duration(int duration)
{
    this->duration = duration;
}

int Reservation::get_id()
{
    return reservation_id;
}