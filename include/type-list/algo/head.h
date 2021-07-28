//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_C36C51A3DB3942A9B3238078ED6BBC50
#define TYPE_LIST_2_C36C51A3DB3942A9B3238078ED6BBC50

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct head {
        template<typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            static_assert(sizeof...(Xs) > 0);
            return holo::get<0>(xs);
        }
    };
}

namespace holo {
    constexpr auto head = detail::apply_op_0<detail::head>{};
}

#endif //TYPE_LIST_2_C36C51A3DB3942A9B3238078ED6BBC50
