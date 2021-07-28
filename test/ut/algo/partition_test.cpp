//
// Created by Darwin Yuan on 2021/7/28.
//
#include <type-list/algo/partition.h>
#include <catch.hpp>

using namespace holo;

SCENARIO("partition") {
    constexpr auto result = partition([](auto elem) {
       return bool_c<(elem.size() > sizeof(int))>;
    }, tuple_c<int, long, char, short, double, unsigned long, bool, long long>);

    static_assert(holo::first(result) == tuple_c<long, double, unsigned long, long long>);
    static_assert(holo::second(result) == tuple_c<int, char, short, bool>);
}