//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/take.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("take") {
    constexpr auto result = take(size_c<0>, tuple_c<int, long>);
    static_assert(result == tuple_c<>);

    constexpr auto result1 = take(size_c<1>, tuple_c<int, long>);
    static_assert(result1 == tuple_c<int>);

    constexpr auto result2 = take(size_c<2>)(tuple_c<int, long>);
    static_assert(result2 == tuple_c<int, long>);
}