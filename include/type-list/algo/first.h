//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_A96E1A5B4B1743CBBD248F4653600025
#define TYPE_LIST_2_A96E1A5B4B1743CBBD248F4653600025

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct first {
        template<typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            static_assert(sizeof...(Xs) > 0);
            return holo::get<0>(xs);
        }
    };
}

namespace holo {
    constexpr auto first = detail::apply_op_0<detail::first>{};
}

#endif //TYPE_LIST_2_A96E1A5B4B1743CBBD248F4653600025
