#ifndef E416A686_C1CA_4FC9_B134_8432EA527B41
#define E416A686_C1CA_4FC9_B134_8432EA527B41

#include "../Constraint/Constraint.h"

#include "../Restaurant/Table.h"
#include "../Restaurant/Branch.h"
#include "../Restaurant/Restaurant.h"
#include "../Actor/Waiter.h"
#include "../Actor/Chef.h"
#include "../Meal/Meal.h"

#include "../Manage/MealManager.h"
class Order
{
private:
	int order_id;
	int creator_id;
	int branch_id;
	int chef_id = -1;
	int check_id = -1;
	int table_id = -1;
	OrderStatus status = O_RECEIVED;
	DayTime creation_time;
	list<Meal> meals;

public:
	static int new_id;
	static string class_name;

	~Order();
	Order();
	Order(
		int _creatorId,
		int _chefId,
		int _checkId,
		int _tableId,
		OrderStatus _status,
		int _branch_id,
		list<Meal> _meals);

	Order(
		int _creatorId,
		int _chefId,
		int _checkId,
		int _tableId,
		OrderStatus _status,
		int _branch_id);

	double getPrice() ;

	bool add_meal(int menu, int table);
	bool add_meal();
	bool remove_meal(Meal);
	Table* pick_table(int branch);

	static Order input(int branch_id, int creator);

	int getOrder_id();
	int get_id();
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
	DayTime getCreation_time();
	void setCreation_time(time_t creation_time);
	list<Meal> *getMeals();
	void setMeals(list<Meal> meals);
	int getBranch_id();
	void setBranch_id(int branch_id);

	friend ostream &operator<<(ostream &os, const Order &order);
	friend ostream &operator<<(ostream &os, const list<Order> &order);
};

#endif /* E416A686_C1CA_4FC9_B134_8432EA527B41 */
