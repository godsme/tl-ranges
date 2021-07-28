//
// Created by Darwin Yuan on 2021/7/28.
//
#include <type-list/algo/contains.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("contains") {
    static_assert(contains(type_c<int>, tuple_c<int, long>));
    static_assert(contains(type_c<long>, tuple_c<int, long>));
    static_assert(!contains(type_c<short>, tuple_c<int, long>));
}
