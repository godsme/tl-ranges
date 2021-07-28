//
// Created by Darwin Yuan on 2021/7/28.
//
#include <type-list/algo/exists.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("exists") {
    constexpr auto result = exists([](auto elem) {
        return (elem.size() > sizeof(int));
    }, tuple_c<int, long>);

    static_assert(std::is_same_v<std::decay_t<decltype(result)>, bool_t<true>>);

    constexpr auto result1 = exists([](auto elem) {
        return elem.size() > sizeof(int);
    }, tuple_c<int, short>);

    static_assert(result1 == bool_c<false>);
}