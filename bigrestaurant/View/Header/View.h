#ifndef C92028D9_5B48_4A83_9095_0FA4FA6EE36B
#define C92028D9_5B48_4A83_9095_0FA4FA6EE36B


#include "../../Actor/Header/Actor.h"
#include "../../Actor/Header/Admin.h"
#include "../../Actor/Header/Employee.h"
#include "../../Actor/Header/Chef.h"
#include "../../Actor/Header/Manager.h"
#include "../../Actor/Header/Receptionist.h"
#include "../../Actor/Header/Waiter.h"
#include "../../Restaurant/Header/Restaurant.h"

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
