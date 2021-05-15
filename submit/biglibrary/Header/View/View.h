#ifndef CDDB27A7_E4CC_48CC_BA16_E282E1D1A995
#define CDDB27A7_E4CC_48CC_BA16_E282E1D1A995
#include "../Actor/Librarian.h"
#include "../Library/Library.h"
// #include "../Actor/Patron.h"
class View
{
public:
    View() {}
    ~View() {}

    // void welcomeView(User *user);
    void startApp(Library *);
    User *login(UserType);
};

#endif /* CDDB27A7_E4CC_48CC_BA16_E282E1D1A995 */
