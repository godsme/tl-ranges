//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/types/type_c.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("type const") {
    static_assert(type_c<int> == type_c<int>);
    static_assert(type_c<int> != type_c<short>);
}