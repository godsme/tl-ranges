//
// Created by Darwin Yuan on 2021/7/28.
//

#include <type-list/algo/fold_left.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("fold_left") {
    constexpr auto result = fold_left(size_c<0>, [](auto&& acc, auto&& elem) {
        return acc + elem.size();
    }, tuple_c<int, long>);

    static_assert(result == size_c<sizeof(int) + sizeof(long)>);

    constexpr auto result1 = fold_left(size_c<0>, [](auto&& acc, auto&& elem) {
        return acc + elem.size();
    })(tuple_c<int, long>);

    static_assert(result1 == size_c<sizeof(int) + sizeof(long)>);
}

SCENARIO("fold_left_1") {
    constexpr auto result = fold_left_1([](auto acc, auto elem) {
        if constexpr(sizeof(typename decltype(acc)::type) > sizeof(typename decltype(elem)::type)) {
            return acc;
        } else {
            return elem;
        }
    }, tuple_c<int, long, short, char>);

    static_assert(result == type_c<long>);

    constexpr auto result1 = fold_left_1([](auto acc, auto elem) {
        if constexpr(sizeof(typename decltype(acc)::type) > sizeof(typename decltype(elem)::type)) {
            return acc;
        } else {
            return elem;
        }
    })(tuple_c<int, long, short, char>);

    static_assert(result1 == type_c<long>);
}