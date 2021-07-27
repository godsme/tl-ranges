//
// Created by Darwin Yuan on 2021/7/27.
//

#include <type-list/algo/elem.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("elem") {
    static_assert(elem(size_c<0>, tuple_c<int, long>) == type_c<int>);
    static_assert(elem(size_c<1>, tuple_c<int, long>) == type_c<long>);
    static_assert(elem(size_c<0>, tuple_c<int, long>) != type_c<long>);
    static_assert(elem(size_c<0>)(tuple_c<int, long>) == type_c<int>);
}