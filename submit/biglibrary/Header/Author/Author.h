#ifndef BDB40F7A_9804_47C8_B08B_62AB66183A78
#define BDB40F7A_9804_47C8_B08B_62AB66183A78

#include "../Constraint/Constraint.h"

class Author
{
private:
    string author_name;
    string biography;
    time_t birth_date;

    static list<Author> authors;

public:
    Author();
    ~Author();
    Author(
        string _author_name,
        string _biography,
        time_t _birth_date)
        : author_name(_author_name),
          biography(_biography),
          birth_date(_birth_date) {}

    static Author* select_author();

    static bool add_author(Author);
   
    static Author* get_author(string name);

    static list<Author>* get_authors();

    static void set_authors(list<Author> authors);

    static Author input();

    void modify();

    friend ostream & operator<<(ostream& os, const Author& a);

    string getAuthor_name();
    void setAuthor_name(string author_name);
    string getBiography();
    void setBiography(string biography);
    time_t getBirth_date();
    void setBirth_date(time_t birth_date);
};
#endif /* BDB40F7A_9804_47C8_B08B_62AB66183A78 */
