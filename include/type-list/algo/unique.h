//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08
#define TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/algo/contains.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct unique {
        template <typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            return holo::fold_left(tuple_c<>, [](auto acc, auto elem) {
                if constexpr(decltype(holo::contains(elem, acc))::value) {
                    return acc;
                } else {
                    return tuple_cat(acc, elem);
                }
            }, xs);
        }
    };
}

namespace holo {
    constexpr auto unique = detail::apply_op_0<detail::unique>{};
}

#endif //TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08
