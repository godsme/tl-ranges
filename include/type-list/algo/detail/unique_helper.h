//
// Created by Darwin Yuan on 2021/7/28.
//

#ifndef TYPE_LIST_2_1BB6B60B482C48B08ED8D9AF66C31B9B
#define TYPE_LIST_2_1BB6B60B482C48B08ED8D9AF66C31B9B

#include <type-list/algo/contains.h>

namespace holo::detail {
    template<typename Xs>
    struct unique_helper {
        constexpr unique_helper(Xs result) : result_(result) {}

        template<typename X>
        constexpr auto operator<<(X x) const {
            if constexpr(decltype(holo::contains(X{}, result_))::value) {
                return unique_helper(result_);
            } else {
                auto result = tuple_cat(result_, x);
                return unique_helper<decltype(result)>(result);
            }
        }

        constexpr auto operator()() const -> auto { return result_; }

    private:
        Xs result_;
    };
}

#endif //TYPE_LIST_2_1BB6B60B482C48B08ED8D9AF66C31B9B
