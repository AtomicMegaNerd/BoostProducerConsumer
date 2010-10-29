/*
 * Holder.hh
 *
 *  Created on: 2010-10-27
 *      Author: cdunphy
 */
#ifndef RCD_ITEM_HH_
#define RCD_ITEM_HH_

#include <string>
#include <iostream>

namespace rcd 
{
    class Item {
        friend std::ostream& operator<<(std::ostream& out, const Item& item);
        static long id;
    public:
        Item() : label("Item" + id) { id++; }
        std::string get_label() const { return label; }        
    private:
        std::string label;
    };
}

#endif /* RCD_ITEM_HH_ */
