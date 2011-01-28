#include "ItemWorker.h"

namespace rcd {

// Static initializations
boost::mutex ItemWorker::iq_mutex;
boost::condition_variable_any ItemWorker::iq_empty;
boost::condition_variable_any ItemWorker::iq_full;

}
