//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/algo/flatten.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("flatten") {
    constexpr auto result = flatten(tuple_c<int, tuple_t<long, short>, double, tuple_t<float, char>>);
    constexpr auto expected = tuple_c<int, long, short, double, float, char>;
    static_assert(result == expected);

    constexpr auto result2 = flatten(tuple_c<int, tuple_t<long, tuple_t<short, long long>>, double, tuple_t<float, char>>);
    constexpr auto expected2 = tuple_c<int, long, short, long long, double, float, char>;
    static_assert(result2 == expected2);
}