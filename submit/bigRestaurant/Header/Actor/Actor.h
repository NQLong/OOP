#ifndef DD762137_02DB_4009_B75B_83937AF6A4A5
#define DD762137_02DB_4009_B75B_83937AF6A4A5
#include "../Constraint/Constraint.h"

#include "Account.h"
class Actor
{

public:
    Actor() {}
    ~Actor() {}
    virtual bool add_employee() = 0;
    virtual bool reassign_employee() = 0;
    virtual void view() = 0;
    virtual EmployeeType getTyp() = 0;
    virtual void setTyp(EmployeeType Typ) = 0;

    virtual int getBranch_id() = 0;
    virtual void setBranch_id(int branch_id) = 0;

    virtual DayTime getDate_joined() = 0;
    virtual void setDate_joined(DayTime date_joined) = 0;

    virtual int getEmployee_id() = 0;
    virtual void setEmployee_id(int employee_id) = 0;

    virtual Account* getAccount() = 0;
    virtual void setAccount(Account account) = 0;

    virtual void printMenu()= 0;
};

class iActor : public Actor
{
public:
    iActor() {}
    ~iActor() {}

    bool add_employee() { return true; }
    bool reassign_employee() { return true; }
    void view() {}
    EmployeeType getTyp() { return MANAGER; }
    void setTyp(EmployeeType Typ) {}

    int getBranch_id() { return 0; }
    void setBranch_id(int branch_id) {}

    DayTime getDate_joined() { return 0; }
    void setDate_joined(DayTime date_joined) {}

    int getEmployee_id() { return 0; }
    void setEmployee_id(int employee_id) {}

    Account* getAccount() { return {}; }
    void setAccount(Account account) {}

    void printMenu(){}
};

#endif /* DD762137_02DB_4009_B75B_83937AF6A4A5 */
