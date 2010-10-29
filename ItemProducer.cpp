#include "ItemProducer.h"

namespace rcd 
{
    void ItemProducer::work() {
        while (true) {
            boost::mutex::scoped_lock p_lock(w_mutex);

            if (iter >= NUM_ITERATIONS)
                break;
            
            // Adding a number to the string messes it up bad!
            Item item("Item", iter);
            iq.push(item);
            std::cout << "Pushed " << item << " into queue!" << std::endl;
            iter++;
            
            p_lock.unlock();
            is_empty.notify_one();
        }
    }
}
