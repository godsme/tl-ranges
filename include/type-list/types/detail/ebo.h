//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_2C15050A93704332906A27357B7F8419
#define TYPE_LIST_2_2C15050A93704332906A27357B7F8419

#include <holo/types/type_c.h>
#include <cstdint>

namespace type_list::detail {
    template<std::size_t K, typename V>
    struct ebo {
        constexpr ebo() = default;
        constexpr ebo(ebo const &rhs) = default;
    };

    template<std::size_t K, typename V>
    consteval auto ebo_get(ebo<K, V> const &x) -> type_t<V> {
        return {};
    }
}

#endif //TYPE_LIST_2_2C15050A93704332906A27357B7F8419
