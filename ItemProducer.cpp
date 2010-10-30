#include "ItemProducer.h"

namespace rcd 
{
    void ItemProducer::work() {
        while (true) {
            boost::mutex::scoped_lock p_lock(iq_mutex);

            if (cur_iteration >= num_iterations)
                break;

            if (iq_queue.full()) {
                iq_full.wait(p_lock);
            }
            
            Item item("Item", cur_iteration);
            iq_queue.push(item);
            std::cout << "Pushed " << item << " into queue!" << std::endl;
            cur_iteration++;
            
            p_lock.unlock();
            iq_empty.notify_one();
        }
    }
}
