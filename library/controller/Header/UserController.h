#ifndef F135D877_0D6A_4207_AA58_0BC2C8F529CB
#define F135D877_0D6A_4207_AA58_0BC2C8F529CB

#include "BaseController.h"
class UserController : public BaseController
{
public:
    UserController();
    ~UserController();

    int createUser(string, string, string, string, char, char);
    int removeUser(string);
    int removeUser(int id);
    int setAccountStatus(string,char);
    list<User *> allUsers();

    User* userOfUsername(string);
    
};

#endif /* F135D877_0D6A_4207_AA58_0BC2C8F529CB */
