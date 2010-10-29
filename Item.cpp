#include "Item.h"
namespace rcd 
{    
    std::ostream& operator<<(std::ostream& out, const Item& item) {
        return out << item.label << item.index;
    }
}



