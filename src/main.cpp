#include <cstring>
#include <iostream>
#include <string>

#include "BoundedQueue.h"
#include "Item.h"
#include "ItemConsumer.h"
#include "ItemProducer.h"

using std::cout;
using std::endl;

using rcd::BoundedQueue;
using rcd::Item;
using rcd::ItemConsumer;
using rcd::ItemProducer;

int main()
{
     // All of our threads will share this bounded
     // queue
     BoundedQueue<Item> item_queue(10);

     // Each thread will iterate over the queue 50
     // times
     ItemProducer p1(item_queue, 50);
     ItemConsumer c1(item_queue, 50);
     ItemProducer p2(item_queue, 50);
     ItemConsumer c2(item_queue, 50);

     p1.start();
     c1.start();
     p2.start();
     c2.start();

     p1.join();
     c1.join();
     p2.join();
     c2.join();

     cout << "Finished!" << endl;

     return 0;
}
