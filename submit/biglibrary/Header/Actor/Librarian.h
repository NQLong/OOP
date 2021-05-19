#ifndef C5C614C8_B801_4EF1_BF35_C289631A78EF
#define C5C614C8_B801_4EF1_BF35_C289631A78EF

#include "../Constraint/Constraint.h"
#include "../../Header/Actor/User.h"
#include "../Library/Library.h"
class Librarian : public User
{
private:
    string position;

public:
    ~Librarian();
    Librarian() : User(LIBRARIAN) {}
    Librarian(
        FullName _full_name,
        Address _address,
        string _position,
        string username,
        string password)
        : User(username, password, _full_name, _address, LIBRARIAN),
          position(_position) {}

    static Librarian *input_librarian();

    void view(Library *);
    void add_user();
    string getPosition();
    void setPosition(string position);
};

#endif /* C5C614C8_B801_4EF1_BF35_C289631A78EF */
