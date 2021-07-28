//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_64E36C1BAFF1462D8C40DE7FEDADFD4D
#define TYPE_LIST_2_64E36C1BAFF1462D8C40DE7FEDADFD4D

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/detail/folder_helper.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct fold_left {
        template <typename INIT, typename F, typename ... Xs>
        constexpr auto operator()(INIT init, F f, tuple_t<Xs...> xs) const -> auto {
            return (fold_helper{init, f} <<  ... << tuple_elem<Xs>)();
        }
    };

    struct fold_left_1 {
        template <typename F, typename X1, typename X2, typename ... Xs>
        constexpr auto operator()(F const& f, tuple_t<X1, X2, Xs...> xs) const -> auto {
            return (fold_helper{f(tuple_elem<X1>, tuple_elem<X2>), f} <<  ... << tuple_elem<Xs>)();
        }

        template <typename F, typename X>
        constexpr static auto apply(F&&, tuple_t<X>) -> tuple_t<X> { return {}; }

        template <typename F>
        constexpr static auto apply(F&&, tuple_t<>) -> tuple_t<> { return {}; }
    };
}

namespace holo {
    constexpr auto fold_left = detail::apply_op_2<detail::fold_left>{};
    constexpr auto fold_left_1 = detail::apply_op_1<detail::fold_left_1>{};
}

#endif //TYPE_LIST_2_64E36C1BAFF1462D8C40DE7FEDADFD4D
