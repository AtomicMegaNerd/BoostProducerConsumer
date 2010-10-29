#include <cstring>
#include <iostream>
#include <string>

#include "ItemConsumer.h"
#include "ItemProducer.h"

using std::cout;
using std::endl;

using rcd::ItemConsumer;
using rcd::ItemProducer;

int main()
{
    ItemProducer p1;
    ItemConsumer c1;

    p1.start();
    c1.start();

    p1.join();
    c1.join();

	cout << "Finished!" << endl;

	return 0;
}
