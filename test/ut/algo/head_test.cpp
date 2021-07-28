//
// Created by Darwin Yuan on 2021/7/29.
//

#include <type-list/algo/head.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("head") {
    constexpr auto result = head(tuple_c<int, long, char>);
    static_assert(result == type_c<int>);
}