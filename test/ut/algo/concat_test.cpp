//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/concat.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("concat") {
    constexpr auto result = concat(tuple_c<int, char>, tuple_c<long, double, short>);
    static_assert(result == tuple_c<long, double, short, int, char>);
}