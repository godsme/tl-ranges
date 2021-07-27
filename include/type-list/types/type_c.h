//
// Created by Darwin Yuan on 2021/7/27.
//

#ifndef TYPE_LIST_2_83551568A5224FA499D85DFF0D418089
#define TYPE_LIST_2_83551568A5224FA499D85DFF0D418089

#include <type-list/types/bool_c.h>
#include <type_traits>

namespace type_list {

    template<typename T> struct type_t {
        using type = T;
    };

    template<typename T>
    constexpr auto type_c = type_t<T>{};

    template<typename T1, typename T2>
    constexpr auto operator==(type_t<T1>, type_t<T2>) -> auto {
        return bool_c<std::is_same_v<T1, T2>>;
    }

    template<typename T1, typename T2>
    constexpr auto operator!=(type_t<T1> lhs, type_t<T2> rhs) -> auto {
        return bool_c<!std::is_same_v<T1, T2>>;
    }
}

#endif //TYPE_LIST_2_83551568A5224FA499D85DFF0D418089
