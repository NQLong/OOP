#ifndef C8F022CC_A926_4D4C_AA43_496DD9836410
#define C8F022CC_A926_4D4C_AA43_496DD9836410
#include "ListManager.h"
#include "../Restaurant/Table.h"

class TableManager
    : public ListManager<Table>
{
public:
    TableManager(void *ptr) : ListManager<Table>(ptr) {}
};
#endif /* C8F022CC_A926_4D4C_AA43_496DD9836410 */
