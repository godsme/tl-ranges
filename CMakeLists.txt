cmake_minimum_required(VERSION 3.19)
project(type_list_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/third-party"
)

set(TYPE_LIST_SRC include/type-list/types/bool_c.h test/ut/bool_c_test.cpp)

add_executable(type_list_test test/ut/catch.cpp ${TYPE_LIST_SRC})
