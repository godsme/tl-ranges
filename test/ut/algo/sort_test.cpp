//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/sort.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("sort") {
    constexpr auto result = sort([](auto &&l, auto &&r) {
        return l.size() < r.size();
    }, tuple_c<int, long, short, char>);

    static_assert(result == tuple_c<char, short, int, long>);

    constexpr auto result1 = sort([](auto &&l, auto &&r) {
        return l.size() < r.size();
    })(tuple_c<int, long, short, char>);

    static_assert(result1 == tuple_c<char, short, int, long>);
}
