//
// Created by Darwin Yuan on 2021/7/29.
//

#include <type-list/algo/remove_if.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("remove_if") {
    constexpr auto result = remove_if([](auto elem) {
        return elem.size() > size_of<int>;
    }, tuple_c<long long, int, long, char, double, int, char, short>);

    static_assert(result == tuple_c<int, char, int, char, short>);
}
