//
// Created by Darwin Yuan on 2021/7/29.
//

#include <type-list/algo/transform.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("transform") {
    constexpr auto result = transform([](auto elem) {
            return tuple_c<typename std::decay_t<decltype(elem)>::type>;
        }, tuple_c<int, long, char>);

    static_assert(result == tuple_c<tuple_t<int>, tuple_t<long>, tuple_t<char>>);
}