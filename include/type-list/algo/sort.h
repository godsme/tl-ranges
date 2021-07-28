//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_DA3357ECD043474BA9425E708D88831E
#define TYPE_LIST_2_DA3357ECD043474BA9425E708D88831E

#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/detail/merge_sort.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct sort {
    private:
        template<typename Xs, std::size_t ... Xn>
        constexpr static auto create(Xs const& xs, std::index_sequence<Xn...>) {
            return holo::make_tuple(get<Xn>(xs) ...);
        }

    public:
        template <typename LT, typename ... Xs>
        constexpr auto operator()(LT, tuple_t<Xs...> xs) const -> auto {
            return create(xs, merge_sort_t<tuple_t<Xs...>, std::decay_t<LT>>{});
        }
    };
}

namespace holo {
    constexpr auto sort = detail::apply_op_1<detail::sort>{};
}

#endif //TYPE_LIST_2_DA3357ECD043474BA9425E708D88831E
