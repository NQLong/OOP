#ifndef B64189AD_EDDE_4D27_AC94_69B9C7830364
#define B64189AD_EDDE_4D27_AC94_69B9C7830364

#include "View.h"
class MemberView : public View
{
private:
    Member *member;

public:
    MemberView() {}
    MemberView( Member *_member) : member(_member){}
    ~MemberView() {}

    void mainCommand();
    void mainView();

    void requestBookView();

    Member *getMember()
    {
        return member;
    }

    void setMember(Member *member)
    {
        this->member = member;
    }
};

#endif /* B64189AD_EDDE_4D27_AC94_69B9C7830364 */
