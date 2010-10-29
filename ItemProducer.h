#ifndef ITEMPRODUCER_H_
#define ITEMPRODUCER_H_

#include "ItemWorker.h"

namespace rcd 
{
    class ItemProducer : public ItemWorker {
    public:
        void work();
    };
}

#endif /* ITEMPRODUCER_H_ */
