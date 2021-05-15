#include "../../Header/Meal/Meal.h"
#include "../../Header/Order/Order.h"
list<Order> Order::orders;

Order::~Order() {}

bool Order::add_order(Order order)
{
    orders.push_back(order);
    return true;
}

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
    os << setw(60) << setfill('#') << "" << endl;
    os << setfill(' ');
    os
        << setw(3) << left << to_string(order.order_id) + "."
        << "Branch id: " << order.branch_id << endl
        << setw(3) << left << ""
        << "Create at: " << (char *)ctime(&order.creation_time)
        << setw(3) << left << ""
        << "Table id: " << order.tableId << endl
        << setw(3) << left << ""
        << "Creator id: " << order.creatorId << endl
        << setw(3) << left << ""
        << "Chef id: " << (order.chefId == -1 ? "" : to_string(order.chefId)) << endl
        << setw(3) << left << ""
        << "Check id: " << (order.checkId == -1 ? "" : to_string(order.checkId)) << endl
        << setw(3) << left << ""
        << "Status: " << order.status << endl
        << endl;

    os
        << setw(35) << right << "MEALS" << endl
        << setw(60) << setfill('+') << "" << endl;
    for (auto it = order.meals.begin(); it != order.meals.end(); it++)
    {
        cout << *it << endl
             << setw(60) << setfill('+') << "" << endl;
    }
    os << setw(60) << setfill('#') << "";
    os << setfill(' ') << ' ';
    return os;
}

int Order::selectOrderId(int branch)
{
    for (auto it = orders.begin(); it != orders.end(); it++)
    {
        cout
            << setw(3) << left << to_string(it->order_id) + "."
            << "At table: " << it->tableId << endl
            << setw(3) << left << ""
            << "Created at: " << (char *)ctime(&it->creation_time)
            << setw(3) << left << ""
            << "Status: " << (OrderStatus)(it->status) << endl;
        ;
    }
    cout << endl;
    cout << "Order id: ";
    int id;
    cin >> id;
    cin.ignore();
    if (!getOrder(id))
        return -1;
    return id;
}

Order *Order::getOrder(int id)
{
    for (auto it = orders.begin(); it != orders.end(); it++)
    {
        if (it->getOrder_id() == id)
            return &(*it);
    }
    return NULL;
}

Order Order::inputOrder(int branch_id, int creator)
{
    clear();
    Order temp;
    temp.creatorId = creator;
    temp.branch_id = branch_id;
    cout << "Table: " << endl;
    temp.tableId = Table::selectTableId(branch_id);
    Table *table = Table::getTable(temp.tableId);
    if (!table)
    {
        cout << "table doesnt exist";
        wait();
        return temp;
    }
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add new meal." << endl
            << endl
            << setw(3) << left << "0."
            << "Done." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            temp.add_meal(table);
            break;
        default:
            loop = false;
            break;
        }
    }
    return temp;
}

bool Order::add_meal(Meal meal)
{
    meals.push_back(meal);
    return true;
}

bool Order::add_meal(Table *table)
{
    clear();
    Meal meal = Meal::inputMeal(table, this->branch_id);
    meal.setMeal_id(meals.size() > 0 ? meals.back().getMeal_id() + 1 : 0);
    return this->add_meal(meal);
}

//*getter setter
list<Order> *Order::getOrders()
{
    return &orders;
}

void Order::setOrders(list<Order> orders)
{
    orders = orders;
}

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
    return this->creatorId;
}

void Order::setCreatorId(int creatorId)
{
    this->creatorId = creatorId;
}

int Order::getChefId()
{
    return this->chefId;
}

void Order::setChefId(int chefId)
{
    this->chefId = chefId;
}

int Order::getCheckId()
{
    return this->checkId;
}

void Order::setCheckId(int checkId)
{
    this->checkId = checkId;
}

int Order::getTableId()
{
    return this->tableId;
}

void Order::setTableId(int tableId)
{
    this->tableId = tableId;
}

OrderStatus Order::getStatus()
{
    return this->status;
}

void Order::setStatus(OrderStatus status)
{
    this->status = status;
}

time_t Order::getCreation_time()
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