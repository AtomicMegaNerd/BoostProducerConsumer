cmake_minimum_required(VERSION 2.8)
include_directories(.)
link_libraries(boost_thread)

set(SRCS
  BoundedQueue.cpp
  ItemConsumer.cpp
  Item.cpp
  ItemProducer.cpp
  ItemWorker.cpp
)

add_library(bpclib ${SRCS})
add_executable(bpc_client main.cpp)
target_link_libraries(bpc_client bpclib)
