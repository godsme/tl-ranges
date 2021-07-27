//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_9911302A627C41A0A4B24D848DCDCB6C
#define TYPE_LIST_2_9911302A627C41A0A4B24D848DCDCB6C

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct elem {
        template<std::size_t N, typename ... Xs>
        constexpr auto operator()(size_c_t<N>, tuple_t<Xs...> xs) const -> auto {
            static_assert(N < sizeof...(Xs));
            return holo::get<N>(xs);
        }
    };
}

namespace holo {
    constexpr auto elem = detail::apply_op_1<detail::elem>{};
}

#endif //TYPE_LIST_2_9911302A627C41A0A4B24D848DCDCB6C
