#ifndef ITEMPRODUCER_H_
#define ITEMPRODUCER_H_

#include "ItemWorker.h"

namespace rcd {

class ItemProducer : public ItemWorker {
public:
     ItemProducer(BoundedQueue<Item>& iq, std::size_t num_iters) :
          ItemWorker(iq, num_iters) { }
     void work();
};

}

#endif /* ITEMPRODUCER_H_ */
