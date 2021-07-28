//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_D5B55D588E024B2488DF90127B602BD2
#define TYPE_LIST_2_D5B55D588E024B2488DF90127B602BD2

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/types/tuple_c.h>
#include <type-list/types/maybe.h>

namespace holo::detail {
    struct find_if {
        template<typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...> xs) const -> auto {
            return holo::nothing_c;
        }

        template<typename PRED, typename X, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<X, Xs...> xs) const -> auto {
            if constexpr(decltype(pred(tuple_elem<X>))::value) {
                return tuple_elem<X>;
            } else {
                return operator()(pred, tuple_c<Xs...>);
            }
        }
    };
}

namespace holo {
    constexpr auto find_if = detail::apply_op_1<detail::find_if>{};
}

#endif //TYPE_LIST_2_D5B55D588E024B2488DF90127B602BD2
