//
// Created by Darwin Yuan on 2021/7/27.
//
#include <type-list/types/bool_c.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("bool const") {
    static_assert(bool_c<true> == bool_c<true>);
    static_assert(bool_c<true> == true);
    static_assert(bool_c<true> != bool_c<false>);
    static_assert(true_c == !false_c);
    static_assert(false_c == !true_c);
    static_assert(true_c != false_c);
    static_assert(true_c);
    static_assert(!false_c);

    static_assert(true_c && true_c);
    static_assert(true_c && true_c && true_c);
    static_assert(!(true_c && false_c && true_c));
    static_assert(true_c || false_c || true_c);
    static_assert(!(false_c || false_c || false_c));
}

