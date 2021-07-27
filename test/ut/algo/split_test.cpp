//
// Created by Darwin Yuan on 2021/7/27.
//
#include <type-list/algo/split.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("split") {
    static_assert(split(size_c<0>, tuple_c<int, long>) == tuple_c<>);
    static_assert(split(size_c<1>, tuple_c<int, long>) == tuple_c<int>);
    static_assert(split(size_c<2>, tuple_c<int, long>) == tuple_c<int, long>);
}
