#ifndef DBE38140_F488_4A7A_AD01_26128EA630DE
#define DBE38140_F488_4A7A_AD01_26128EA630DE

#include "BaseController.h"

class AuthorController : public BaseController
{
public:
    AuthorController();
    ~AuthorController();

    // int createUser(string, string, string, string, char, char){}
    
    int createAuthor(string, char);
    int removeAuthor(string);
};

#endif /* DBE38140_F488_4A7A_AD01_26128EA630DE */
