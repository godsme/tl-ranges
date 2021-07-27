//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D
#define TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D

#include <type-list/types/tuple_c.h>

namespace holo::detail {
    template<typename OP>
    struct apply_op_1 : OP {
        using OP::operator();
        template<typename ARG>
        constexpr auto operator()(ARG&& arg) const -> auto {
            return [=](auto&& xs) {
                return OP::operator()(arg, xs);
            };
        }
    };
}

#endif //TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D
