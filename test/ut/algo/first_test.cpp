//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/algo/first.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("first") {
    static_assert(first(tuple_c<int, long>) == type_c<int>);
    static_assert(first()(tuple_c<int, long>) == type_c<int>);
}