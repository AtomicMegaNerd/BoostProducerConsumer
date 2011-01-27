cmake_minimum_required(VERSION 2.8)
project(BoostProducerConsumer)

# Put the binaries in their place
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

# Libraries we depend on
link_libraries(boost_thread)

# Lots of warnings
if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-Wall -Wextra -pedantic -Werror)
endif(CMAKE_COMPILER_IS_GNUCXX)

# The sources for our library
set(bpc_srcs
  BoundedQueue.cpp
  ItemConsumer.cpp
  Item.cpp
  ItemProducer.cpp
  ItemWorker.cpp
)

add_library(bpc ${bpc_srcs})
add_executable(bpc_client main.cpp)
target_link_libraries(bpc_client bpc)
