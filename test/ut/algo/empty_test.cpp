//
// Created by Darwin Yuan on 2021/7/28.
//
#include <type-list/algo/empty.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("empty") {
    static_assert(!empty(tuple_c<int, long>));
    static_assert(empty(tuple_c<>));
}
