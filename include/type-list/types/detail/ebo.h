//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_2C15050A93704332906A27357B7F8419
#define TYPE_LIST_2_2C15050A93704332906A27357B7F8419

#include <type-list/types/type_c.h>
#include <cstdlib>

namespace holo::detail {
    template<std::size_t K, typename V, bool = std::is_empty_v<V>>
    struct ebo {
        using type = V;
    };

    template<std::size_t K, typename V>
    struct ebo<K, V, false> {
        using type = type_t<V>;
    };

    template<std::size_t K, typename V>
    constexpr auto ebo_get(ebo<K, V> const &x) -> auto {
        return typename ebo<K, V>::type{};
    }
}

#endif //TYPE_LIST_2_2C15050A93704332906A27357B7F8419
