#ifndef C901EE98_5765_49A9_A638_5A7BC6CAD0D9
#define C901EE98_5765_49A9_A638_5A7BC6CAD0D9

#include "../../Header/Constraint/constraint.h"
#include <list>
#include "TableSeat.h"

class Table
{
private:
    int table_id;
    int max_acpacity;
    int location_id;
    int branch_id;
    TableStatus status;
    list<TableSeat> seats;
    static list<Table> tables;

public:
    Table();
    ~Table();
    Table(int _table_id, int _max_acpacity, int _location_id, int _branch_id)
        : table_id(_table_id), max_acpacity(_max_acpacity), location_id(_location_id), branch_id(_branch_id) {}

    static Table inputTable(int branch);

    bool add_seat(TableSeat);
    bool add_seat();
    bool modify_seat();
    int selectSeatId();

    bool modify_table();
    bool isTableFree();

    bool add_reservation();

    static int selectTableId(int branch);

    static bool addTable(Table);
    static Table *getTable(int id);
    static list<Table> *getTables();
    static void setTables(list<Table> tables);

    int getTable_id();
    void setTable_id(int table_id);
    int getMax_acpacity();
    void setMax_acpacity(int max_acpacity);
    int getLocation_id();
    void setLocation_id(int location_id);
    int getBranch_id();
    void setBranch_id(int branch_id);
    TableStatus getStatus();
    void setStatus(TableStatus status);
    list<TableSeat> getSeats();
    void setSeats(list<TableSeat> seats);
};

#endif /* C901EE98_5765_49A9_A638_5A7BC6CAD0D9 */
