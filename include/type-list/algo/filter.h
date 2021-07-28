//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_9D8171544D2B4797805DFE6866348475
#define TYPE_LIST_2_9D8171544D2B4797805DFE6866348475

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct filter {
        template<typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...> xs) const -> auto {
            return holo::fold_left(tuple_c<>, [&](auto acc, auto elem) {
                if constexpr(decltype(pred(elem))::value) {
                    return tuple_cat(acc, elem);
                } else {
                    return acc;
                }
            }, xs);
        }
    };
}

namespace holo {
    constexpr auto filter = detail::apply_op_1<detail::filter>{};
}

#endif //TYPE_LIST_2_9D8171544D2B4797805DFE6866348475
