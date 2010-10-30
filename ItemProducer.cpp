#include "ItemProducer.h"

namespace rcd 
{
    void ItemProducer::work() {
        while (true) {
            boost::mutex::scoped_lock p_lock(iq_mutex);

            if (iter >= NUM_ITERATIONS)
                break;

            if (iq_queue.size() >= MAX_QUEUE_SIZE)
            {
                iq_full.wait(p_lock);
            }
            
            // Adding a number to the string messes it up bad!
            Item item("Item", iter);
            iq_queue.push(item);
            std::cout << "Pushed " << item << " into queue!" << std::endl;
            iter++;
            
            p_lock.unlock();
            iq_empty.notify_one();
        }
    }
}
