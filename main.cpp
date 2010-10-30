#include <cstring>
#include <iostream>
#include <string>
#include <queue>

#include "Item.h"
#include "ItemConsumer.h"
#include "ItemProducer.h"

using std::cout;
using std::endl;
using std::queue;

using rcd::Item;
using rcd::ItemConsumer;
using rcd::ItemProducer;

int main()
{
    queue<Item> item_queue;
    
    ItemProducer p1(item_queue);
    ItemConsumer c1(item_queue);

    p1.start();
    c1.start();

    p1.join();
    c1.join();

	cout << "Finished!" << endl;

	return 0;
}
