/*
 * ItemProducer.h
 *
 *  Created on: 2010-10-27
 *      Author: cdunphy
 */

#ifndef ITEMPRODUCER_H_
#define ITEMPRODUCER_H_

#include <iostream>
#include <queue>

#include <boost/thread.hpp>

#include "Item.hh"
#include "ItemWorker.hh"

namespace rcd 
{
    class ItemProducer : public ItemWorker {
    public:
        ItemProducer(std::queue<Item>& iq) : ItemWorker(iq) { }
        void work();
    };
}

#endif /* ITEMPRODUCER_H_ */
