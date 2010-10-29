/*
 * ItemConsumer.h
 *
 *  Created on: 2010-10-27
 *      Author: cdunphy
 */

#ifndef ITEMCONSUMER_H_
#define ITEMCONSUMER_H_

#include <iostream>
#include <queue>

#include <boost/thread.hpp>

#include "Item.hh"
#include "ItemWorker.hh"

namespace rcd 
{
    class ItemConsumer : public ItemWorker {
    public:
        ItemConsumer(std::queue<Item>& iq) : ItemWorker(iq) { }
        void work();
    };
}

#endif /* ITEMCONSUMER_H_ */
