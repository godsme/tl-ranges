//
// Created by Darwin Yuan on 2021/7/27.
//
#include <type-list/algo/split.h>
#include <type-list/algo/first.h>
#include <type-list/algo/second.h>
#include <catch.hpp>

using namespace holo;

template<typename T> struct S;

SCENARIO("split") {
    constexpr auto result = split(size_c<0>, tuple_c<int, long>);
    static_assert(first(result) == tuple_c<>);
    static_assert(second(result) == tuple_c<int, long>);
    static_assert(split(size_c<0>, tuple_c<int, long>) == tuple_c<tuple_t<>, tuple_t<int, long>>);
    static_assert(split(size_c<1>, tuple_c<int, long>) == tuple_c<tuple_t<int>, tuple_t<long>>);
    static_assert(split(size_c<2>, tuple_c<int, long>) == tuple_c<tuple_t<int, long>, tuple_t<>>);
}
