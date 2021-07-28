//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/append.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("append") {
    constexpr auto result = append(type_c<int>, tuple_c<long, double, short>);
    static_assert(result == tuple_c<long, double, short, int>);
}
