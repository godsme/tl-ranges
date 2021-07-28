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
}