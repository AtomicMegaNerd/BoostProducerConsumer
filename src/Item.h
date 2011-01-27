#ifndef RCD_ITEM_HH_
#define RCD_ITEM_HH_

#include <string>
#include <cstddef>
#include <iostream>

namespace rcd 
{    
    class Item {
        friend std::ostream& operator<<(std::ostream& out, const Item& item);
    public:
        Item(std::string lbl, std::size_t ix) : label(lbl), index(ix) { }
        const std::string get_label() const { return label; }
        const std::size_t get_index() const { return index; }
    private:
        std::string label;
        std::size_t index;
    };
}

#endif /* RCD_ITEM_HH_ */