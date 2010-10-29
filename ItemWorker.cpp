/*
 * ItemWorker.cpp
 *
 *  Created on: 2010-10-28
 *      Author: cdunphy
 */

#include "ItemWorker.hh"

namespace rcd 
{
    // Static initializations
    boost::mutex ItemWorker::w_mutex;
    boost::condition_variable_any ItemWorker::is_empty;
}
