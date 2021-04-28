#ifndef Data_included
#define Data_included

#include "Catalog.h"
#include "Librarian.h"
#include "Member.h"
#include "Author.h"

class Data
{
private:
    static Catalog *catalog;

    static list<Member *> members;

    static list<Author *> authors;

    static list<Librarian *> librarians;

    static list<User *> users;

    static list<BookRequest *> requests;

public:
    Data();

    bool addMember(Member *);
    bool addLibrarian(Librarian *);
    bool addBookRequest(BookRequest *);
    bool addAuthor(Author *);

    bool existMember(string userName);
    bool existLibrarian(string userName);
    bool existAuthor(string name);

    bool removeAuthor(Author *);
    bool removeLibrarian(User *user);
    bool removeMember(User *user);
    bool removeUser(User *user);

    /*getter and setter*/
    Author *getAuthor(string name);

    Librarian *getLibrarian(string userName);

    Member *getMember(string userName);

    Catalog *getCatalog();

    void setCatalog(Catalog *catalog);

    list<BookRequest *> getRequests();

    void setRequests(list<BookRequest *> requests);

    list<Member *> getMembers();

    void setMembers(list<Member *> member);

    list<Librarian *> getLibrarians();

    void setLibrarians(list<Librarian *> librarian);

    list<Member *> getMembers(string name);

    Member *getMember(int id);

    list<Librarian *> getLibrarians(string name);

    Librarian *getLibrarian(int id);

    list<Author *> getAuthors();

    void setAuthors(list<Author *> authors);

    list<User *> getUsers();

    void setUsers(list<User *> users);

    User* getUser(int id);
    User* getUser(string username);

    list<BookRequest*> getRequests(char status);
    
    BookRequest* getRequest(int code);
};

#endif