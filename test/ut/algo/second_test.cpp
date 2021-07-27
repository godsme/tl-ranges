//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/algo/second.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("second") {
    static_assert(second(tuple_c<int, long>) == type_c<long>);
    static_assert(second()(tuple_c<int, long>) == type_c<long>);
}