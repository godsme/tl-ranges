//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_A82C44A522484F7DBD00D6447704E995
#define TYPE_LIST_2_A82C44A522484F7DBD00D6447704E995

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct append {
        template <typename X, typename ... Xs>
        constexpr auto operator()(X x, tuple_t<Xs...> xs) const -> auto {
            return tuple_cat(xs, x);
        }
    };
}

namespace holo {
    constexpr auto append = detail::apply_op_1<detail::append>{};
}

#endif //TYPE_LIST_2_A82C44A522484F7DBD00D6447704E995
