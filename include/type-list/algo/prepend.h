//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_64CD6A1C353C40FABEFDC6450356D9E9
#define TYPE_LIST_2_64CD6A1C353C40FABEFDC6450356D9E9

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct prepend {
        template <typename X, typename ... Xs>
        constexpr auto operator()(X x, tuple_t<Xs...> xs) const -> auto {
            return tuple_c<X, Xs...>;
        }
    };
}

namespace holo {
    constexpr auto prepend = detail::apply_op_1<detail::prepend>{};
}

#endif //TYPE_LIST_2_64CD6A1C353C40FABEFDC6450356D9E9
