#include "../../Header/Restaurant/Restaurant.h"

string Restaurant::name;
list<Branch> Restaurant::branches;
list<Employee *> Restaurant::employees;

bool Restaurant::addEmployee(EmployeeType Typ, int _branch_id)
{
    string name, email, phone, wait;
    int id;

    clear();
    cout << "Add new " << Typ << ":" << endl
         << endl;
    cout << Typ << "'s Name :";
    getline(cin, name);
    cout << Typ << "'s email :";
    getline(cin, email);
    cout << Typ << "'s phone :";
    getline(cin, phone);
    Account account = Account::inputAccount();
    if (getEmployee(account.getUsername()))
    {
        cout << "invalid username";
        getline(cin, wait);
        return false;
    }
    id = Restaurant::employees.back() ? Restaurant::employees.back()->getEmployee_id() + 1 : 0;
    Employee *newAccount = NULL;
    switch (Typ)
    {
    case MANAGER:
        newAccount = new Manager(id, name, account, email, phone, _branch_id);
        break;
    case WAITER:
        newAccount = new Waiter(id, name, account, email, phone, _branch_id);
        break;
    case CHEF:
        newAccount = new Chef(id, name, account, email, phone, _branch_id);
        break;
    case RECEPTIONIST:
        newAccount = new Receptionist(id, name, account, email, phone, _branch_id);
        break;
    }
    Restaurant::addEmployee(newAccount);
    return true;
}

Restaurant::Restaurant(string _name)
{
    name = _name;
}

bool Restaurant::addBranch(Branch br)
{
    branches.push_back(br);
    return true;
}

bool Restaurant::addBranch()
{
    cout << "Add new Branch:" << endl
         << endl;

    Branch br = Branch::inputBranch();

    if (getBranch(br.getName()))
    {
        cout << "Invalid Branch name";
        wait();
        clear();
        return false;
    }

    br.setBranch_id(&branches.back() ? branches.back().getBranch_id() + 1 : 0);
    addBranch(br);
    cout << "Success";
    wait();
    return true;
}

Branch *Restaurant::getBranch(int id)
{
    for (auto it = branches.begin(); it != branches.cend(); it++)
    {
        if (it->getBranch_id() == id)
        {
            return &(*it);
        }
    }
    return NULL;
}

Branch *Restaurant::getBranch(string name)
{
    for (auto it = branches.begin(); it != branches.cend(); it++)
    {
        if (it->getName() == name)
        {
            return &(*it);
        }
    }
    return NULL;
}

Employee *Restaurant::getEmployee(string username, string password, EmployeeType Typ, AccountStatus stat)
{
    Employee *temp = getEmployee(username, password, Typ);
    if (temp)
        if (temp->getAccount()->getStatus() == stat)
            return temp;
    return NULL;
}

Employee *Restaurant::getEmployee(string username, string password, EmployeeType Typ)
{
    for (auto it = employees.begin(); it != employees.cend(); it++)
    {
        if ((*it)->getAccount()->getUsername() == username && (*it)->getAccount()->getPassword() == password && (*it)->getTyp() == Typ)
        {   

            return (*it);
        }
    }
    cout<<"fine none;";;
    wait();
    return NULL;
}

Employee *Restaurant::getEmployee(string username)
{
    for (auto it = employees.begin(); it != employees.cend(); it++)
    {
        if ((*it)->getAccount()->getUsername() == username)
        {
            return (*it);
        }
    }
    return NULL;
}

Employee *Restaurant::getEmployee(int id)
{
    for (auto it = employees.begin(); it != employees.cend(); it++)
    {
        if ((*it)->getEmployee_id() == id)
        {
            return (*it);
        }
    }
    return NULL;
}

/*getter and setter*/
string Restaurant::getName()
{
    return name;
}

void Restaurant::setName(string _name)
{
    name = _name;
}

list<Branch> *Restaurant::getBranches()
{
    return &branches;
}

void Restaurant::setBranches(list<Branch> _branches)
{
    branches = _branches;
}

list<Employee *> Restaurant::getEmployees()
{
    return employees;
}

void Restaurant::setEmployees(list<Employee *> _employees)
{
    employees = _employees;
}

bool Restaurant::addEmployee(Employee *employee)
{
    employees.push_back(employee);
    return true;
}
