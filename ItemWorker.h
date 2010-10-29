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
        const static std::size_t NUM_ITERATIONS = 50;
        ItemWorker() : iter(0) { }
        virtual ~ItemWorker() { }

        void start() { work_thread = boost::thread(&ItemWorker::work, this); }
        void join() { work_thread.join(); }
        virtual void work() = 0;

    protected:
        std::size_t iter;
        static std::queue<Item> iq; // shared
        static boost::mutex w_mutex; // shared
        static boost::condition_variable_any is_empty; // shared

    private:
        boost::thread work_thread; // each instance has own thread
    };
}

#endif /* ITEMWORKER_H_ */
