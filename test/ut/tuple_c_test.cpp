//
// Created by Darwin Yuan on 2021/7/27.
//
#include <type-list/types/tuple_c.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("tuple const") {
    static_assert(tuple_c<int, double> == tuple_c<int, double>);
    static_assert(tuple_c<int, double> != tuple_c<int>);
    static_assert(tuple_c<int, double> != tuple_c<int, short>);

    static_assert(get<0>(tuple_c<int, double>) == type_c<int>);
    static_assert(get<1>(tuple_c<int, double>) == type_c<double>);
    static_assert(get<0>(tuple_c<int, double>) != type_c<double>);
    static_assert(get<1>(tuple_c<int, double>) != type_c<int>);
}