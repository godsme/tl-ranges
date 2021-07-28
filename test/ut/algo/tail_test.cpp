//
// Created by Darwin Yuan on 2021/7/29.
//

#include <type-list/algo/tail.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("tail") {
    constexpr auto result = tail(tuple_c<int, long, char>);
    static_assert(result == tuple_c<long, char>);

    constexpr auto result1 = tail(result);
    static_assert(result1 == tuple_c<char>);

    constexpr auto result2 = tail(result1);
    static_assert(result2 == tuple_c<>);
}