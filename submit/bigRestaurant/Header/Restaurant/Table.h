#ifndef C901EE98_5765_49A9_A638_5A7BC6CAD0D9
#define C901EE98_5765_49A9_A638_5A7BC6CAD0D9

#include "../../Header/Constraint/Constraint.h"
#include "../../Header/Constraint/Enum.h"
#include "TableSeat.h"
#include "../../Header/Manage/ListManager.h"

class Table
    : ListManager<TableSeat>
{
private:
    int table_id;
    int max_acpacity = 0;
    int location_id = -1;
    int branch_id;
    TableStatus status = T_FREE;
    list<TableSeat> seats;

    static int new_id;

public:
    static string class_name;

    friend ostream &operator<<(ostream &os, const Table &seat);
    friend ostream &operator<<(ostream &, const list<Table> &);
    friend bool operator==(const Table &lhs, const Table &rhs)
    {
        return (
            (lhs.table_id == rhs.table_id) &&
            (lhs.branch_id == rhs.branch_id) &&
            (lhs.max_acpacity == rhs.max_acpacity) &&
            (lhs.status == rhs.status) &&
            (lhs.seats == rhs.seats) &&
            true

        );
    }

    Table();
    ~Table();
    Table( int _location_id, int _branch_id,list<TableSeat> seats );

    static Table input(int branch);

    
    bool add_seat();
    bool modify_seat();
    TableSeat* pick_seat();


    int selectSeatId();

    bool modify_table();
    bool isTableFree();

    bool add_reservation();

    static int selectTableId(int branch);

    int getTable_id();
    int get_id();
    void setTable_id(int table_id);
    int getMax_acpacity();
    void setMax_acpacity(int max_acpacity);
    int getLocation_id();
    void setLocation_id(int location_id);
    int get_branch_id();
    void setBranch_id(int branch_id);
    TableStatus getStatus();
    void setStatus(TableStatus status);
    list<TableSeat>* getSeats();
    void setSeats(list<TableSeat> seats);
};

#endif /* C901EE98_5765_49A9_A638_5A7BC6CAD0D9 */
