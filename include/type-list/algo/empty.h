//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_1DECEA2BC570460484D290E744F5B3C5
#define TYPE_LIST_2_1DECEA2BC570460484D290E744F5B3C5

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct empty {
        template<typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...>) const -> auto {
            return bool_c<sizeof...(Xs) == 0>;
        }
    };
}

namespace holo {
    constexpr auto empty = detail::apply_op_0<detail::empty>{};
}

#endif //TYPE_LIST_2_1DECEA2BC570460484D290E744F5B3C5
