//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_E50DE2C3163B4BAA886DE4C1377EC8D1
#define TYPE_LIST_2_E50DE2C3163B4BAA886DE4C1377EC8D1

#include <type-list/types/bool_c.h>
#include <cstdlib>
#include <limits>

namespace holo {
    template<std::size_t V>
    struct size_c_t {
        static constexpr std::size_t value = V;
        using size_t = std::size_t;
        constexpr operator size_t() const {
            return V;
        }
    };

    template<std::size_t V>
    constexpr auto size_c = size_c_t<V>{};

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator==(size_c_t<V1>, size_c_t<V2>) -> auto {
        return bool_c<V1 == V2>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator!=(size_c_t<V1> lhs, size_c_t<V2> rhs) -> auto {
        return !operator==(lhs, rhs);
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator+(size_c_t<V1>, size_c_t<V2>) -> auto {
        static_assert(std::numeric_limits<std::size_t>::max() - V1 >= V2);
        return size_c<V1 + V2>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator-(size_c_t<V1>, size_c_t<V2>) -> auto {
        static_assert(V1 >= V2);
        return size_c<V1 - V2>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator>(size_c_t<V1>, size_c_t<V2>) -> auto {
        return bool_c<(V1 > V2)>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator>=(size_c_t<V1>, size_c_t<V2>) -> auto {
        return bool_c<V1 >= V2>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator<(size_c_t<V1>, size_c_t<V2>) -> auto {
        return bool_c<V1 < V2>;
    }

    template<std::size_t V1, std::size_t V2>
    constexpr auto operator<=(size_c_t<V1>, size_c_t<V2>) -> auto {
        return bool_c<V1 <= V2>;
    }
}

#endif //TYPE_LIST_2_E50DE2C3163B4BAA886DE4C1377EC8D1
