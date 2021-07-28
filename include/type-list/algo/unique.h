//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08
#define TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08


#include <type-list/algo/detail/apply_op.h>
#include <type-list/algo/detail/unique_helper.h>
#include <type-list/types/tuple_c.h>

namespace holo::detail {
    struct unique {
        template <typename ... Xs>
        constexpr auto operator()(tuple_t<Xs...> xs) const -> auto {
            return (unique_helper(tuple_c<>) << ... << tuple_elem<Xs>)();
        }
    };
}

namespace holo {
    constexpr auto unique = detail::apply_op_0<detail::unique>{};
}

#endif //TYPE_LIST_2_CC85291452214D58ADB7E9D92CF99A08
