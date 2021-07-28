//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/drop_while.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("drop_while") {
    constexpr auto result = drop_while([](auto elem) {
        return bool_c<(elem.size() > sizeof(int))>;
        }, tuple_c<long long, long, double, int, char, short>);

    static_assert(result == tuple_c<int, char, short>);
}