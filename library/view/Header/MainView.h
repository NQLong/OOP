#ifndef FE77C293_2E9C_4F24_AAD9_DD6C80962821
#define FE77C293_2E9C_4F24_AAD9_DD6C80962821


#include "LibrarianView.h"
#include "MemberView.h"
#include "../../controller/Header/Controller.h"

class MainView
{
public:
    MainView(){}
    ~MainView(){}

    void welcomeView(User *user);
    void startApp();
    User* login();
};

#endif /* FE77C293_2E9C_4F24_AAD9_DD6C80962821 */
