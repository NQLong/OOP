#ifndef E4179EAF_A2ED_401A_9445_32D8AB4DE4E8
#define E4179EAF_A2ED_401A_9445_32D8AB4DE4E8

#include "Employee.h"
#include "Actor.h"
#include "../../Restaurant/Header/Restaurant.h"
#include "../../Constraint/constraint.h"

class Admin : public Employee
// , public iActor
{
private:
public:
    Admin();
    ~Admin();
    Admin(int _id, string _name, Account _account, string _email, string _phone) : 
    Employee(_id, _name, _account, _email, _phone, ADMIN) {}


    bool assignManager();

    bool addBranch();
    bool addManager();
    
    bool removeManager();
    bool removeBranch();

    void managerManage();
    void branchManage();

    void view();

    // friend ostream& operator <<(ostream& os, const Admin& a){
    //      os << ((Employee)a);
    // }
};


#endif /* E4179EAF_A2ED_401A_9445_32D8AB4DE4E8 */
