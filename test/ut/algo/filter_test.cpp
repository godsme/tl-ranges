//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/filter.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("filter") {
    constexpr auto result = filter([](auto elem) {
        return elem.size() > size_of<int>;
    }, tuple_c<long long, int, long, char, double, int, char, short>);

    static_assert(result == tuple_c<long long, long, double>);
}