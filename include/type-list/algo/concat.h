//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_3E396D3258584359981AD60209D2F10D
#define TYPE_LIST_2_3E396D3258584359981AD60209D2F10D

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct concat {
        template <typename ... Xs, typename ... Ys>
        constexpr auto operator()(tuple_t<Ys...> ys, tuple_t<Xs...> xs) const -> auto {
            return tuple_c<Xs..., Ys...>;
        }
    };
}

namespace holo {
    constexpr auto concat = detail::apply_op_1<detail::concat>{};
}

#endif //TYPE_LIST_2_3E396D3258584359981AD60209D2F10D
