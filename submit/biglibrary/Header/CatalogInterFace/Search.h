#ifndef FC97DA8F_222B_41AA_848D_FDC683037087
#define FC97DA8F_222B_41AA_848D_FDC683037087

#include "../Constraint/Constraint.h"
#include "../Book/BookItem.h"

class Search
{
public:
    virtual void search_view() = 0;
    virtual BookItem *search_by_barcode() = 0;
    virtual void search_by_title() = 0;
    virtual void search_by_ISBN() = 0;
};

#endif /* FC97DA8F_222B_41AA_848D_FDC683037087 */
