#include "ItemConsumer.h"

namespace rcd 
{
    void ItemConsumer::work() {
        while (true) {
            boost::mutex::scoped_lock c_lock(iq_mutex);

            if (iter >= NUM_ITERATIONS)
                break;
            
            while (iq_queue.empty()) {
                iq_empty.wait(c_lock);
            }
                     
            Item item = iq_queue.front();
            iq_queue.pop();
            std::cout << "Popped " << item << " from the queue" << std::endl;
            iter++;
            
            c_lock.unlock();
            iq_full.notify_one();
        }
    }
}
