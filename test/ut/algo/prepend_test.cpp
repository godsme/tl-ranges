//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/prepend.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("prepend") {
    constexpr auto result = prepend(type_c<int>, tuple_c<long, double, short>);
    static_assert(result == tuple_c<int, long, double, short>);
}