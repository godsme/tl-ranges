//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_491B8769C72D44A0B4198C2C2BF8954B
#define TYPE_LIST_2_491B8769C72D44A0B4198C2C2BF8954B

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct contains {
        template<typename T, typename ... Xs>
        constexpr auto operator()(T, tuple_t<Xs...>) const -> auto {
            return bool_c<((type_c<T> == type_c<Xs>) || ...)>;
        }
    };
}

namespace holo {
    constexpr auto contains = detail::apply_op_1<detail::contains>{};
}

#endif //TYPE_LIST_2_491B8769C72D44A0B4198C2C2BF8954B
