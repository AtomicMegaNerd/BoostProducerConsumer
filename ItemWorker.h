#ifndef ITEMWORKER_H_
#define ITEMWORKER_H_

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>

#include <boost/thread.hpp>

#include "Item.h"

namespace rcd 
{
    class ItemWorker {        
    public:
        const static std::size_t MAX_QUEUE_SIZE = 50;
        const static std::size_t NUM_ITERATIONS = 500;
        
        ItemWorker(std::queue<Item>& iq) : iq_queue(iq), iter(0) { }
        virtual ~ItemWorker() { }

        void start() { work_thread = boost::thread(&ItemWorker::work, this); }
        void join() { work_thread.join(); }
        virtual void work() = 0;

    protected:
        std::size_t iter;
        std::queue<Item>& iq_queue; // shared
        static boost::mutex iq_mutex; // shared
        static boost::condition_variable_any iq_empty; // shared
        static boost::condition_variable_any iq_full; // shared

    private:
        boost::thread work_thread; // each instance has own thread
    };
}

#endif /* ITEMWORKER_H_ */
