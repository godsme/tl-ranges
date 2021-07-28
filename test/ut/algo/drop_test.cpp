//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/drop.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("split") {
    constexpr auto result = drop(size_c<0>, tuple_c<int, long>);
    static_assert(result == tuple_c<int, long>);

    constexpr auto result1 = drop(size_c<1>, tuple_c<int, long>);
    static_assert(result1 == tuple_c<long>);

    constexpr auto result2 = drop(size_c<2>)(tuple_c<int, long>);
    static_assert(result2 == tuple_c<>);
}