#ifndef ITEMWORKER_H_
#define ITEMWORKER_H_

#include <iostream>
#include <cstddef>
#include <string>

#include <boost/thread.hpp>

#include "BoundedQueue.h"
#include "Item.h"

namespace rcd 
{
    class ItemWorker {        
    public:
        ItemWorker(BoundedQueue<Item>& iq, std::size_t num_iters) : 
            iq_queue(iq), num_iterations(num_iters), cur_iteration(0) { }
        virtual ~ItemWorker() { }

        void start() { 
            work_thread = boost::thread(&ItemWorker::work, this); 
        }
        void join() { work_thread.join(); }
        virtual void work() = 0;

    protected:
        BoundedQueue<Item>& iq_queue; // shared
        std::size_t num_iterations;
        std::size_t cur_iteration;
        
        static boost::mutex iq_mutex; // shared
        static boost::condition_variable_any iq_empty; // shared
        static boost::condition_variable_any iq_full; // shared

    private:
        boost::thread work_thread; // each instance has own thread
    };
}

#endif /* ITEMWORKER_H_ */
