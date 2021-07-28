//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_2374D28E55784477AED354605CE07C98
#define TYPE_LIST_2_2374D28E55784477AED354605CE07C98

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct drop_while {
        template<typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...> xs) const -> auto {
            return holo::fold_left(tuple_c<>, [&](auto acc, auto elem) {
                if constexpr(acc.size() > 0 || !decltype(pred(elem))::value) {
                    return tuple_cat(acc, elem);
                } else {
                    return acc;
                }
            }, xs);
        }
    };
}

namespace holo {
    constexpr auto drop_while = detail::apply_op_1<detail::drop_while>{};
}

#endif //TYPE_LIST_2_2374D28E55784477AED354605CE07C98
