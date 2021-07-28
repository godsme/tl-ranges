//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_6F1823D0EE40490BAAB932DDC4D4DA7F
#define TYPE_LIST_2_6F1823D0EE40490BAAB932DDC4D4DA7F

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct remove_if {
        template<typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...> xs) const -> auto {
            return holo::fold_left(tuple_c<>, [=](auto acc, auto elem) {
                if constexpr(decltype(pred(elem))::value) {
                    return acc;
                } else {
                    return tuple_cat(acc, elem);
                }
            }, xs);
        }
    };
}

namespace holo {
    constexpr auto remove_if = detail::apply_op_1<detail::remove_if>{};
}

#endif //TYPE_LIST_2_6F1823D0EE40490BAAB932DDC4D4DA7F
