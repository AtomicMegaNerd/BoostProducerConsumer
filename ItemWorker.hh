/*
 * ItemWorker.h
 *
 *  Created on: 2010-10-28
 *      Author: cdunphy
 */

#ifndef ITEMWORKER_H_
#define ITEMWORKER_H_

#include <cstddef>
#include <queue>

#include <boost/thread.hpp>

#include "Item.hh"

namespace rcd 
{
    class ItemWorker {
        const static int NUM_ITERATIONS = 50;
    public:
        ItemWorker(std::queue<Item>& iq) : queue(iq) { }
        virtual ~ItemWorker() { }

        void start() { work_thread = boost::thread(&ItemWorker::work, this); }
        void join() { work_thread.join(); }
        virtual void work() = 0;

    protected:
        std::queue<Item>& queue; // shared by reference
        static boost::mutex w_mutex; // shared
        static boost::condition_variable_any is_empty; // shared

    private:
        boost::thread work_thread; // each instance has own thread
    };
}

#endif /* ITEMWORKER_H_ */
