//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/unique.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("unique") {
    constexpr auto result = unique(tuple_c<int, long, int, long, int, char>);
    static_assert(result == tuple_c<int, long, char>);

    constexpr auto result1 = unique(tuple_c<int, tuple_t<long, int>, long, int, tuple_t<long, int>, char>);
    static_assert(result1 == tuple_c<int, tuple_t<long, int>, long, char>);
}