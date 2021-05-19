#ifndef C92028D9_5B48_4A83_9095_0FA4FA6EE36B
#define C92028D9_5B48_4A83_9095_0FA4FA6EE36B


#include "../Actor/Actor.h"
#include "../Actor/Admin.h"
#include "../Actor/Employee.h"
#include "../Actor/Chef.h"
#include "../Actor/Manager.h"
#include "../Actor/Receptionist.h"
#include "../Actor/Waiter.h"
#include "../Restaurant/Restaurant.h"

class View
{
public:
    View(){}
    ~View(){}

    // void welcomeView(User *user);
    void startApp();
    Employee* login(EmployeeType);
};




#endif /* C92028D9_5B48_4A83_9095_0FA4FA6EE36B */
