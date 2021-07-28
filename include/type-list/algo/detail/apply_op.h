//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D
#define TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D

#include <type-list/types/tuple_c.h>

namespace holo::detail {
    template<typename OP>
    struct apply_op_0 : OP {
        using OP::operator();

        constexpr auto operator()() const -> auto {
            return [this](auto&& xs) {
                return OP::operator()(xs);
            };
        }
    };

    template<typename OP>
    struct apply_op_1 : OP {
        using OP::operator();
        template<typename ARG>
        constexpr auto operator()(ARG&& arg) const -> auto {
            return [&](auto&& xs) {
                return OP::operator()(arg, xs);
            };
        }
    };

    template<typename OP>
    struct apply_op_2 : OP {
        using OP::operator();
        template<typename ARG1, typename ARG2>
        constexpr auto operator()(ARG1&& arg1, ARG2&& arg2) const -> auto {
            return [&](auto&& xs) {
                return OP::operator()(arg1, arg2, xs);
            };
        }
    };
}

#endif //TYPE_LIST_2_9A6DA6C34C1F4CF3AC183904B2D4565D
