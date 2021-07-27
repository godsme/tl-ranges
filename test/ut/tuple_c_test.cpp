//
// Created by Darwin Yuan on 2021/7/27.
//
#include <type-list/types/tuple_c.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("tuple const") {
    static_assert(tuple_c<int, double> == tuple_c<int, double>);
    static_assert(tuple_c<int, double> != tuple_c<int>);
    static_assert(tuple_c<int, double> != tuple_c<int, short>);
}