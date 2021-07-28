cmake_minimum_required(VERSION 3.19)
project(type_list_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/third-party"
)

set(TYPE_LIST_SRC include/type-list/types/bool_c.h test/ut/bool_c_test.cpp test/ut/type_c_test.cpp include/type-list/types/tuple_c.h test/ut/tuple_c_test.cpp include/type-list/types/size_c.h test/ut/size_c_test.cpp include/type-list/algo/detail/apply_op.h include/type-list/algo/elem.h test/ut/algo/elem_test.cpp include/type-list/algo/split.h test/ut/algo/split_test.cpp include/type-list/algo/first.h test/ut/algo/first_test.cpp include/type-list/algo/second.h test/ut/algo/second_test.cpp include/type-list/algo/flatten.h test/ut/algo/flatten_test.cpp include/type-list/algo/detail/folder_helper.h include/type-list/algo/fold_left.h test/ut/algo/fold_left_test.cpp include/type-list/algo/detail/merge_sort.h include/type-list/algo/sort.h test/ut/algo/sort_test.cpp include/type-list/algo/contains.h test/ut/algo/contains_test.cpp include/type-list/algo/exists.h test/ut/algo/exists_test.cpp include/type-list/algo/unique.h test/ut/algo/unique_test.cpp include/type-list/algo/partition.h test/ut/algo/partition_test.cpp include/type-list/algo/append.h test/ut/algo/append_test.cpp include/type-list/algo/prepend.h include/type-list/algo/prepend.h test/ut/algo/prepend_test.cpp include/type-list/algo/concat.h test/ut/algo/concat_test.cpp include/type-list/algo/drop.h test/ut/algo/drop_test.cpp include/type-list/algo/take.h test/ut/algo/take_test.cpp include/type-list/algo/drop_while.h test/ut/algo/drop_while_test.cpp include/type-list/algo/empty.h test/ut/algo/empty_test.cpp include/type-list/algo/filter.h test/ut/algo/filter_test.cpp include/type-list/algo/remove_if.h test/ut/algo/remove_if_test.cpp include/type-list/algo/transform.h test/ut/algo/transform_test.cpp include/type-list/algo/head.h test/ut/algo/head_test.cpp include/type-list/algo/tail.h test/ut/algo/tail_test.cpp include/type-list/types/multi_map.h include/type-list/algo/find_if.h include/type-list/types/maybe.h test/ut/algo/find_if_test.cpp)

add_executable(type_list_test test/ut/catch.cpp ${TYPE_LIST_SRC})
