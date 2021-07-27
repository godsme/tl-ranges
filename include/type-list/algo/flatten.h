//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_0FE965D60F0C49ED9C3CFE6634B2362E
#define TYPE_LIST_2_0FE965D60F0C49ED9C3CFE6634B2362E

#include <type-list/algo/detail/apply_op.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct flatten {
    private:
        template<typename X>
        constexpr auto do_flatten(X x) const -> auto {
            return tuple_c<X>;
        }

        template<typename ... Xs>
        constexpr auto do_flatten(tuple_t<Xs...> xs) const -> auto {
            return (do_flatten(Xs{}) + ...) ;
        }

    public:
        template<typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            return do_flatten(xs);
        }
    };
}

namespace holo {
    constexpr auto flatten = detail::apply_op_0<detail::flatten>{};
}

#endif //TYPE_LIST_2_0FE965D60F0C49ED9C3CFE6634B2362E
