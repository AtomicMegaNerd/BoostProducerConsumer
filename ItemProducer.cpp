#include "ItemProducer.h"

namespace rcd 
{
    void ItemProducer::work() {
        int iters = 0;
        while (true) {
            boost::mutex::scoped_lock lock(w_mutex);

            if (iters >= NUM_ITERATIONS)
                break;
            
            Item item;
            item_queue.push(item);
            std::cout << "Pushed " << item
                    << " into the back of the queue!" << std::endl;
            iters++;
            
            lock.unlock();
            is_empty.notify_one();
        }
    }
}
