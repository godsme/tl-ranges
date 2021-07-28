//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_C17224B702354DFA953506C02FA201A8
#define TYPE_LIST_2_C17224B702354DFA953506C02FA201A8

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/fold_left.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct transform {
        template<typename MAPPER, typename ... Xs>
        constexpr auto operator()(MAPPER mapper, tuple_t<Xs...>) const -> auto {
            return make_tuple(mapper(tuple_elem<Xs>)...);
        }
    };
}

namespace holo {
    constexpr auto transform = detail::apply_op_1<detail::transform>{};
}

#endif //TYPE_LIST_2_C17224B702354DFA953506C02FA201A8
