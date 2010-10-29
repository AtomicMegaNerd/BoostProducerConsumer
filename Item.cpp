#include "Item.hh"
namespace rcd 
{
    // Static initializer
    long Item::id = 0L;

    std::ostream& operator<<(std::ostream& out, const Item& item) {
        return out << item.label << Item::id;
    }
}

