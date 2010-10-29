/*
 * ItemConsumer.cpp
 *
 *  Created on: 2010-10-27
 *      Author: cdunphy
 */

#include "ItemConsumer.hh"

using boost::mutex;

namespace rcd 
{
    void ItemConsumer::work() {
        int iters = 0;
        while (true) {
            boost::mutex::scoped_lock lock(w_mutex);

            while (queue.empty()) {
                is_empty.wait(lock);
            }
            
            if (iters >= NUM_ITERATIONS)
                break;

            Item item = item_queue.front();
            item_queue.pop();
            std::cout << "Popped " << item
                    << " from the front of the queue" << std::endl;
            iters++;
        }
    }
}
