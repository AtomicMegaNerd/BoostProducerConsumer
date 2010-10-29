#include "ItemConsumer.h"

namespace rcd 
{
    void ItemConsumer::work() {
        while (true) {
            boost::mutex::scoped_lock c_lock(w_mutex);

            if (iter >= NUM_ITERATIONS)
                break;
            
            while (iq.empty()) {
                is_empty.wait(c_lock);
            }
                     
            Item item = iq.front();
            iq.pop();
            std::cout << "Popped " << item << " from the queue" << std::endl;
            
            iter++;
        }
    }
}
