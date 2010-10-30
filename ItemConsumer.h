#ifndef ITEMCONSUMER_H_
#define ITEMCONSUMER_H_

#include "ItemWorker.h"

namespace rcd 
{
    class ItemConsumer : public ItemWorker {
    public:
        ItemConsumer(std::queue<Item>& iq) : ItemWorker(iq) { }
        void work();
    };
}

#endif /* ITEMCONSUMER_H_ */
