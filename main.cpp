#include <cstring>
#include <iostream>
#include <queue>

#include "Item.hh"
#include "ItemConsumer.hh"
#include "ItemProducer.hh"

using std::cout;
using std::endl;
using std::queue;

using rcd::Item;
using rcd::ItemConsumer;
using rcd::ItemProducer;

int main()
{
	queue<Item> iq;
	ItemProducer p1(iq);
	ItemConsumer c1(iq);

	p1.start();
	c1.start();

	p1.join();
	c1.join();

	cout << "Finished!" << endl;

	return 0;
}
