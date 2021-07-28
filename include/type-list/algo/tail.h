//
// Created by Darwin Yuan on 2021/7/29.
//

#ifndef TYPE_LIST_2_73E416C3C9C34608A71B7BE1438161EF
#define TYPE_LIST_2_73E416C3C9C34608A71B7BE1438161EF

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct tail {
        template<typename X, typename ... Xs>
        constexpr auto operator()(tuple_t<X, Xs...> xs) const -> auto {
            return tuple_c<Xs...>;
        }
    };
}

namespace holo {
    constexpr auto tail = detail::apply_op_0<detail::tail>{};
}

#endif //TYPE_LIST_2_73E416C3C9C34608A71B7BE1438161EF
