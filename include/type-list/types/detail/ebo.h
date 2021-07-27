//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_2C15050A93704332906A27357B7F8419
#define TYPE_LIST_2_2C15050A93704332906A27357B7F8419

#include <type-list/types/type_c.h>
#include <cstdlib>

namespace holo::detail {
    template<std::size_t K, typename V>
    struct ebo {
        static_assert(std::is_empty_v<V>);
        constexpr ebo() {}
        constexpr ebo(ebo const &rhs) = default;
    };

    template<std::size_t K, typename V>
    constexpr auto ebo_get(ebo<K, V> const &x) -> V {
        return {};
    }
}

#endif //TYPE_LIST_2_2C15050A93704332906A27357B7F8419
