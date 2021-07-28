//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_1569984783784C61A8DFBCFB48CC1706
#define TYPE_LIST_2_1569984783784C61A8DFBCFB48CC1706

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct exists {
        template<typename PRED, typename ... Xs>
        constexpr auto operator()(PRED pred, tuple_t<Xs...>) const -> auto {
            return bool_c<(pred(tuple_elem<Xs>) || ...)>;
        }
    };
}

namespace holo {
    constexpr auto exists = detail::apply_op_1<detail::exists>{};
}

#endif //TYPE_LIST_2_1569984783784C61A8DFBCFB48CC1706
