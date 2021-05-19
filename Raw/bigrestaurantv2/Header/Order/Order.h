#ifndef E416A686_C1CA_4FC9_B134_8432EA527B41
#define E416A686_C1CA_4FC9_B134_8432EA527B41

#include "../Constraint/constraint.h"

#include "../Restaurant/Table.h"

#include "../Actor/Waiter.h"
#include "../Actor/Chef.h"
#include "../Meal/Meal.h"


#include <list>
#include <ctime>
class Order
{
private:
    int order_id;
    int creatorId;
    int branch_id;
    int chefId = -1;
    int checkId = -1;
    int tableId;
    OrderStatus status = O_RECEIVED;

    time_t creation_time;
    // Meal meals;
    list<Meal> meals;

    static list<Order> orders;

public:
    Order() : creation_time(time(0)) {}
    ~Order();
    Order(int _order_id,
          int _creatorId,
          int _chefId,
          int _checkId,
          int _tableId,
          OrderStatus _status,
          int _branch_id,
          list<Meal> _meals)
        : order_id(_order_id),
          creatorId(_creatorId),
          chefId(_chefId),
          checkId(_checkId),
          tableId(_tableId),
          status(_status),
          creation_time(time(0)),
          branch_id(_branch_id),
          meals(_meals) {}

    Order(int _order_id,
          int _creatorId,
          int _chefId,
          int _checkId,
          int _tableId,
          OrderStatus _status,
          int _branch_id)
        : order_id(_order_id),
          creatorId(_creatorId),
          chefId(_chefId),
          checkId(_checkId),
          tableId(_tableId),
          status(_status),
          creation_time(time(0)),
          branch_id(_branch_id) {}

    static bool add_order(Order);

    double getPrice();

    bool add_meal(Meal);
    bool add_meal(Table *);

    bool remove_meal(Meal);

    static int selectOrderId(int branch);

    static Order inputOrder(int branch_id, int creator);

    static Order *getOrder(int);

    static Order inputOrder();
    int getOrder_id();
    void setOrder_id(int order_id);
    int getCreatorId();
    void setCreatorId(int creatorId);
    int getChefId();
    void setChefId(int chefId);
    int getCheckId();
    void setCheckId(int checkId);
    int getTableId();
    void setTableId(int tableId);
    OrderStatus getStatus();
    void setStatus(OrderStatus status);
    time_t getCreation_time();
    void setCreation_time(time_t creation_time);
    list<Meal> *getMeals();
    void setMeals(list<Meal> meals);
    int getBranch_id();
    void setBranch_id(int branch_id);


    static list<Order> *getOrders();
    static void setOrders(list<Order> orders);

    friend ostream &operator<<(ostream &os, const Order &order);
};

#endif /* E416A686_C1CA_4FC9_B134_8432EA527B41 */
