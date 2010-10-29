#include "ItemWorker.h"

namespace rcd 
{
    // Static initializations
    std::queue<Item> ItemWorker::iq;
    boost::mutex ItemWorker::w_mutex;
    boost::condition_variable_any ItemWorker::is_empty;
}
