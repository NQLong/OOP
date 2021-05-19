#ifndef AE8D4D28_6A84_4D90_BC72_93B80D0588E1
#define AE8D4D28_6A84_4D90_BC72_93B80D0588E1

#include "ListManager.h"
#include "../Reservation/Reservation.h"

class ReservationManager
    : public ListManager<Reservation>
{
public:
    ReservationManager(void *ptr) : ListManager<Reservation>(ptr) {}

    list<Reservation> get_confirmed_reservations_for_table(int table);
};



#endif /* AE8D4D28_6A84_4D90_BC72_93B80D0588E1 */
