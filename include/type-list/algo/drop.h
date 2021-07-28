//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_B98BBF9BF1624279A4962AB75CD20E6A
#define TYPE_LIST_2_B98BBF9BF1624279A4962AB75CD20E6A

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct drop {
    private:
        template<std::size_t N, std::size_t ... Yn, typename ... Xs>
        constexpr static auto apply(std::index_sequence<Yn...>, tuple_t<Xs...> xs) -> auto {
            return make_tuple(holo::get<Yn + N>(xs) ...);
        }

    public:
        template<std::size_t N, typename ... Xs>
        constexpr auto operator()(size_c_t<N>, tuple_t<Xs...> xs) const -> auto {
            static_assert(N <= sizeof...(Xs));
            return apply<N>(std::make_index_sequence<sizeof...(Xs) - N>{}, xs);
        }
    };
}

namespace holo {
    constexpr auto drop = detail::apply_op_1<detail::drop>{};
}

#endif //TYPE_LIST_2_B98BBF9BF1624279A4962AB75CD20E6A
