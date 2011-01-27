#ifndef ITEMCONSUMER_H_
#define ITEMCONSUMER_H_

#include "ItemWorker.h"

namespace rcd 
{
    class ItemConsumer : public ItemWorker {
    public:
        ItemConsumer(BoundedQueue<Item>& iq, std::size_t num_iters) : 
            ItemWorker(iq, num_iters) { }
        void work();
    };
}

#endif /* ITEMCONSUMER_H_ */
