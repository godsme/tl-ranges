//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/types/size_c.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("size const") {
    static_assert(size_c<10> == 10);
    static_assert(size_c<10> != 11);
    static_assert(size_c<10> < 11);
    static_assert(size_c<10> <= 11);
    static_assert(size_c<10> >= 10);
    static_assert(size_c<10> > 9);

    static_assert(size_c<10> + size_c<11> == size_c<21>);
}