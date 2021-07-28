//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_86DDFC2832AF4ADEAC7A03A3F56E8671
#define TYPE_LIST_2_86DDFC2832AF4ADEAC7A03A3F56E8671

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/algo/first.h>
#include <type-list/algo/second.h>
#include <type-list/algo/contains.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct partition {
        template <typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...> xs) const -> auto {
            return holo::fold_left(tuple_c<tuple_t<>, tuple_t<>>, [](auto acc, auto elem) {
                if constexpr(decltype(pred(elem))::value) {
                    return holo::make_tuple(tuple_cat(holo::first(acc), elem), holo::second(acc));
                } else {
                    return holo::make_tuple(holo::first(acc), tuple_cat(holo::second(acc), elem));
                }
            }, xs);
        }
    };
}

namespace holo {
    constexpr auto partition = detail::apply_op_1<detail::partition>{};
}

#endif //TYPE_LIST_2_86DDFC2832AF4ADEAC7A03A3F56E8671
