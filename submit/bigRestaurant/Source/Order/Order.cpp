#include "../../Header/Order/Order.h"

int Order::new_id = 0;
string Order::class_name = "order";

Order::~Order() {}

Order::Order() : creation_time(time(0)), order_id(new_id++) {}

Order::Order(
    int _creatorId,
    int _chefId,
    int _checkId,
    int _tableId,
    OrderStatus _status,
    int _branch_id,
    list<Meal> _meals)
    : order_id(new_id++),
      creator_id(_creatorId),
      chef_id(_chefId),
      check_id(_checkId),
      table_id(_tableId),
      status(_status),
      creation_time(time(0)),
      branch_id(_branch_id),
      meals(_meals) {}

Order::Order(
    int _creatorId,
    int _chefId,
    int _checkId,
    int _tableId,
    OrderStatus _status,
    int _branch_id)
    : order_id(new_id++),
      creator_id(_creatorId),
      chef_id(_chefId),
      check_id(_checkId),
      table_id(_tableId),
      status(_status),
      creation_time(time(0)),
      branch_id(_branch_id) {}

double Order::getPrice()
{
    double total = 0;
    for (auto it = this->meals.begin(); it != this->meals.end(); it++)
    {
        total += it->getPrice();
    }
    return total;
}

ostream &operator<<(ostream &os, const Order &order)
{
    Order temp = order;
    double price = temp.getPrice();
    int space = 20;
    os
        << setw(space) << left << "Order id"
        << ": " << order.order_id << endl
        << setw(space) << left << "Branch id"
        << ": " << order.branch_id << endl
        << setw(space) << left << "For table"
        << ": " << order.table_id << endl
        << setw(space) << left << "Creat by"
        << ": " << order.creation_time << endl
        << setw(space) << left << "Prepare by"
        << ": " << (order.chef_id == -1 ? "Unknown" : to_string(order.chef_id)) << endl
        << setw(space) << left << "Check id"
        << ": " << (order.check_id == -1 ? "Unknown" : to_string(order.check_id)) << endl
        << setw(space) << left << "Price"
        << ": " << price << endl
        << setw(space) << left << "Meals"
        << ": " << ' ' << endl
        << order.meals;
    return os;
}

ostream &operator<<(ostream &os, const list<Order> &order)
{
    return os;
}

Table *Order::pick_table(int branch)
{
    return ListManager<Table>(Storage::tables).pick_element(branch);
}

Order Order::input(int branch_id, int creator_id)
{
    Order temp;
    temp.branch_id = branch_id;
    temp.creator_id = creator_id;
    cout << "From table:\n";
    Branch *branch = ((Restaurant *)(Storage::Restaurant))->get_element(branch_id);
    if (!branch)
    {
        temp.order_id = -1;
        return temp;
    }
    Menu *menu = branch->get_menu();
    if (!menu)
    {
        temp.order_id = -1;
        return temp;
    }
    Table *table = temp.pick_table(branch_id);
    while (!table)
    {
        clear();
        cout << "Invalid table id";
        wait();
        clear();
        if (!select_statement("peak tables list", "Continue pick table"))
            cout << ListManager<Table>(Storage::tables).get_element_from_branch(branch_id);
        table = temp.pick_table(branch_id);
    }
    temp.table_id = table->get_id();
    clear();
    while (!select_statement("Add meal", "Done"))
    {
        clear();
        temp.add_meal(menu->get_id(), table->get_id());
        wait();
        clear();
    }
    return temp;
}

bool Order::add_meal(int menu, int table)
{
    return MealManager(&this->meals).add_element(menu, table);
}

//*getter setter

int Order::getOrder_id()
{
    return this->order_id;
}

void Order::setOrder_id(int order_id)
{
    this->order_id = order_id;
}

int Order::getCreatorId()
{
    return this->creator_id;
}

void Order::setCreatorId(int creatorId)
{
    this->creator_id = creatorId;
}

int Order::getChefId()
{
    return this->chef_id;
}

void Order::setChefId(int chefId)
{
    this->chef_id = chefId;
}

int Order::getCheckId()
{
    return this->check_id;
}

void Order::setCheckId(int checkId)
{
    this->check_id = checkId;
}

int Order::getTableId()
{
    return this->table_id;
}

void Order::setTableId(int tableId)
{
    this->table_id = tableId;
}

OrderStatus Order::getStatus()
{
    return this->status;
}

void Order::setStatus(OrderStatus status)
{
    this->status = status;
}

DayTime Order::getCreation_time()
{
    return this->creation_time;
}

void Order::setCreation_time(time_t creation_time)
{
    this->creation_time = creation_time;
}

list<Meal> *Order::getMeals()
{
    return &this->meals;
}

void Order::setMeals(list<Meal> meals)
{
    this->meals = meals;
}

int Order::getBranch_id()
{
    return branch_id;
}
void Order::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}