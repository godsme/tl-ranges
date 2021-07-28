//
// Created by Darwin Yuan on 2021/7/29.
//

#include <type-list/algo/find_if.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("find_if") {
    constexpr auto result = find_if([](auto elem) {
        return elem.size() < size_of<int>;
        }, tuple_c<long long, int, long, char, double, int, char, short>);

    static_assert(result == type_c<char>);

    constexpr auto result1 = find_if([](auto elem) {
        return elem.size() == size_c<0>;
        }, tuple_c<long long, int, long, char, double, int, char, short>);

    static_assert(result1 == nothing_c);
}