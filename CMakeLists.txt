cmake_minimum_required(VERSION 2.8)
project(BoostProducerConsumer)

include(MacroOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please, see README.")

add_subdirectory(src)
