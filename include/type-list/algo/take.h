//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_04E14A6F266B464296EB940956C4BE5E
#define TYPE_LIST_2_04E14A6F266B464296EB940956C4BE5E

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct take {
    private:
        template<std::size_t ... Xn, typename ... Xs>
        constexpr static auto apply(std::index_sequence<Xn...>, tuple_t<Xs...> xs) -> auto {
            return make_tuple(holo::get<Xn>(xs) ...);
        }

    public:
        template<std::size_t N, typename ... Xs>
        constexpr auto operator()(size_c_t<N>, tuple_t<Xs...> xs) const -> auto {
            static_assert(N <= sizeof...(Xs));
            return apply(std::make_index_sequence<N>{}, xs);
        }
    };
}

namespace holo {
    constexpr auto take = detail::apply_op_1<detail::take>{};
}

#endif //TYPE_LIST_2_04E14A6F266B464296EB940956C4BE5E
