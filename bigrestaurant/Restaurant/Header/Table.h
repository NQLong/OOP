#ifndef C901EE98_5765_49A9_A638_5A7BC6CAD0D9
#define C901EE98_5765_49A9_A638_5A7BC6CAD0D9

#include "../../Constraint/constraint.h"
#include <list>
#include "TableSeat.h"

class Table
{
private:
    int table_id;
    int max_acpacity;
    int locatio_id;
    TableStatus status;
    list<TableSeat> seats;

public:
    bool isTableFree();
    bool add_reservation();
};

#endif /* C901EE98_5765_49A9_A638_5A7BC6CAD0D9 */
