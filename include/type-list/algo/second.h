//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_B1BB582A873E45DDB5FE283BE286DE95
#define TYPE_LIST_2_B1BB582A873E45DDB5FE283BE286DE95

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct second {
        template<typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            static_assert(sizeof...(Xs) > 1);
            return holo::get<1>(xs);
        }
    };
}

namespace holo {
    constexpr auto second = detail::apply_op_0<detail::second>{};
}

#endif //TYPE_LIST_2_B1BB582A873E45DDB5FE283BE286DE95
