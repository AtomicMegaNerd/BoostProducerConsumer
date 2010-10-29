#include "ItemWorker.h"

namespace rcd 
{
    // Static initializations
    boost::mutex ItemWorker::w_mutex;
    boost::condition_variable_any ItemWorker::is_empty;
}
