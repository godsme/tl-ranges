//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_6979412285CF47AAB673390FDBB35677
#define TYPE_LIST_2_6979412285CF47AAB673390FDBB35677

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct split {
    private:
        template<std::size_t N, std::size_t ... Xn, std::size_t ... Yn, typename ... Xs>
        constexpr auto do_split(std::index_sequence<Xn...>, std::index_sequence<Yn...>, tuple_t<Xs...> xs) const -> auto {
            return make_tuple(make_tuple(holo::get<Xn>(xs) ...), make_tuple(holo::get<Yn + N>(xs) ...));
        }

    public:
        template<std::size_t N, typename ... Xs>
        constexpr auto operator()(size_c_t<N>, tuple_t<Xs...> xs) const -> auto {
            static_assert(N <= sizeof...(Xs));
            return do_split<N>(std::make_index_sequence<N>{}, std::make_index_sequence<sizeof...(Xs) - N>{}, xs);
        }
    };
}

namespace holo {
    constexpr auto split = detail::apply_op_1<detail::split>{};
}

#endif //TYPE_LIST_2_6979412285CF47AAB673390FDBB35677
