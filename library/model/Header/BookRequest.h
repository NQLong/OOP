/*
BookRequest
-----------------------
-BLcode: string
-memberID: int
-ISBN: string
-dueDate: int
-returnDate: int
---------------------------
+getBLcode(): string
+getMemberID(): int
+getISBN(): string
+getDueDate(): int
+getReturnDate(): int

+setBLcode(string): void
+setMemberID(int): void 
+setISBN(string): void 
+setDueDate(): int
+setReturnDate(): int
*/

#ifndef BookRequest_included
#define BookRequest_included

#include <string>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

class BookRequest
{
private:
    int BLcode;
    string ISBN;
    int memberID;
    time_t dueDate;
    time_t returnDate = 0;
    char status;

public:
    BookRequest();
    BookRequest(int, string, int, time_t);

    int getBLcode();

    void setBLcode(int BLcode);

    string getISBN();

    void setISBN(string ISBN);

    int getMemberID();

    void setMemberID(int memberID);

    time_t getDueDate();

    void setDueDate(time_t dueDate);

    time_t getReturnDate();

    void setReturnDate(time_t returnDate);

    char getStatus();

    void setStatus(const char *status);

    friend ostream &operator<<(ostream &os, const BookRequest &);
};

#endif