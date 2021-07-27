cmake_minimum_required(VERSION 3.19)
project(type_list_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/third-party"
)

set(TYPE_LIST_SRC include/type-list/types/bool_c.h test/ut/bool_c_test.cpp test/ut/type_c_test.cpp include/type-list/types/tuple_c.h test/ut/tuple_c_test.cpp include/type-list/types/size_c.h test/ut/size_c_test.cpp include/type-list/algo/detail/apply_op.h include/type-list/algo/elem.h test/ut/algo/elem_test.cpp include/type-list/algo/split.h test/ut/algo/split_test.cpp include/type-list/algo/first.h test/ut/algo/first_test.cpp include/type-list/algo/second.h test/ut/algo/second_test.cpp include/type-list/algo/flatten.h test/ut/algo/flatten_test.cpp)

add_executable(type_list_test test/ut/catch.cpp ${TYPE_LIST_SRC})
